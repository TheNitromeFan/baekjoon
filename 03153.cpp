#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

int find_right(char map[][MAX], int r, int s, int x, int y){
	for(int j = y + 1; j < s; ++j){
		if(map[x][j] == 'T'){
			return j;
		}else if(map[x][j] == '#'){
			break;
		}
	}
	return -1;
}

int find_down(char map[][MAX], int r, int s, int x, int y){
	for(int i = x + 1; i < r; ++i){
		if(map[i][y] == 'T'){
			return i;
		}else if(map[i][y] == '#'){
			break;
		}
	}
	return -1;
}

int find_left(char map[][MAX], int r, int s, int x, int y){
	for(int j = y - 1; j >= 0; --j){
		if(map[x][j] == 'T'){
			return j;
		}else if(map[x][j] == '#'){
			break;
		}
	}
	return -1;
}

int find_up(char map[][MAX], int r, int s, int x, int y){
	for(int i = x - 1; i >= 0; --i){
		if(map[i][y] == 'T'){
			return i;
		}else if(map[i][y] == '#'){
			break;
		}
	}
	return -1;
}

void traverse(vector<int> &post_order, vector<vector<int>> &adj, vector<bool> &visited, int a){
	if(visited[a]){
		return;
	}
	visited[a] = true;
	for(int b : adj[a]){
		traverse(post_order, adj, visited, b);
	}
	post_order.push_back(a);
}

void assign(vector<vector<int>> &rev, vector<int> &assigned, int b, int root){
	if(assigned[b] != -1){
		return;
	}
	assigned[b] = root;
	for(int a : rev[b]){
		assign(rev, assigned, a, root);
	}
}

int main(){
	int r, s;
	scanf("%d %d", &r, &s);
	char map[MAX][MAX];
	int turret_count = 0;
	int turret[MAX][MAX] = {};
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < s; ++j){
			if(map[i][j] == 'T'){
				++turret_count;
				turret[i][j] = turret_count;
			}
		}
	}
	vector<vector<int>> adj(4 * turret_count + 1), rev(4 * turret_count + 1);
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < s; ++j){
			if(map[i][j] != 'T'){
				continue;
			}
			int n = turret[i][j];
			int xn = 2 * n - 1, yn = 2 * n;
			int j1 = find_right(map, r, s, i, j);
			if(j1 != -1){
				int m = turret[i][j1];
				int xm = 2 * m - 1;
				adj[xn].push_back(4 * turret_count + 1 - xn);
				rev[4 * turret_count + 1 - xn].push_back(xn);
				adj[4 * turret_count + 1 - xm].push_back(xm);
				rev[xm].push_back(4 * turret_count + 1 - xm);
			}
			int i1 = find_down(map, r, s, i, j);
			if(i1 != -1){
				int m = turret[i1][j];
				int ym = 2 * m;
				adj[yn].push_back(4 * turret_count + 1 - yn);
				rev[4 * turret_count + 1 - yn].push_back(yn);
				adj[4 * turret_count + 1 - ym].push_back(ym);
				rev[ym].push_back(4 * turret_count + 1 - ym);
			}
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < s; ++j){
			if(map[i][j] != 'n'){
				continue;
			}
			int j1 = find_right(map, r, s, i, j);
			int j2 = find_left(map, r, s, i, j);
			int i1 = find_down(map, r, s, i, j);
			int i2 = find_up(map, r, s, i, j);
			if(j1 != -1 && j2 != -1 && i1 != -1){
				int n = turret[i1][j];
				int yn = 2 * n;
				adj[yn].push_back(4 * turret_count + 1 - yn);
				rev[4 * turret_count + 1 - yn].push_back(yn);
			}else if(j1 != -1 && j2 != -1){
				int n = turret[i2][j];
				int yn = 2 * n;
				adj[4 * turret_count + 1 - yn].push_back(yn);
				rev[yn].push_back(4 * turret_count + 1 - yn);
			}else if(i1 != -1 && i2 != -1 && j1 != -1){
				int n = turret[i][j1];
				int xn = 2 * n - 1;
				adj[xn].push_back(4 * turret_count + 1 - xn);
				rev[4 * turret_count + 1 - xn].push_back(xn);
			}else if(i1 != -1 && i2 != -1){
				int n = turret[i][j2];
				int xn = 2 * n - 1;
				adj[4 * turret_count + 1 - xn].push_back(xn);
				rev[xn].push_back(4 * turret_count + 1 - xn);
			}else if(j1 != -1 && i1 != -1){
				int n = turret[i][j1];
				int m = turret[i1][j];
				int xn = 2 * n - 1;
				int ym = 2 * m;
				adj[xn].push_back(4 * turret_count + 1 - ym);
				rev[4 * turret_count + 1 - ym].push_back(xn);
				adj[ym].push_back(4 * turret_count + 1 - xn);
				rev[4 * turret_count + 1 - xn].push_back(ym);
			}else if(j1 != -1 && i2 != -1){
				int n = turret[i][j1];
				int m = turret[i2][j];
				int xn = 2 * n - 1;
				int ym = 2 * m;
				adj[xn].push_back(ym);
				rev[ym].push_back(xn);
				adj[4 * turret_count + 1 - ym].push_back(4 * turret_count + 1 - xn);
				rev[4 * turret_count + 1 - xn].push_back(4 * turret_count + 1 - ym);
			}else if(j2 != -1 && i1 != -1){
				int n = turret[i][j2];
				int m = turret[i1][j];
				int xn = 2 * n - 1;
				int ym = 2 * m;
				adj[4 * turret_count + 1 - xn].push_back(4 * turret_count + 1 - ym);
				rev[4 * turret_count + 1 - ym].push_back(4 * turret_count + 1 - xn);
				adj[ym].push_back(xn);
				rev[xn].push_back(ym);
			}else if(j2 != -1 && i2 != -1){
				int n = turret[i][j2];
				int m = turret[i2][j];
				int xn = 2 * n - 1;
				int ym = 2 * m;
				adj[4 * turret_count + 1 - xn].push_back(ym);
				rev[ym].push_back(4 * turret_count + 1 - xn);
				adj[4 * turret_count + 1 - ym].push_back(xn);
				rev[xn].push_back(4 * turret_count + 1 - ym);
			}else if(j1 != -1){
				int n = turret[i][j1];
				int xn = 2 * n - 1;
				adj[xn].push_back(4 * turret_count + 1 - xn);
				rev[4 * turret_count + 1 - xn].push_back(xn);
			}else if(j2 != -1){
				int n = turret[i][j2];
				int xn = 2 * n - 1;
				adj[4 * turret_count + 1 - xn].push_back(xn);
				rev[xn].push_back(4 * turret_count + 1 - xn);
			}else if(i1 != -1){
				int n = turret[i1][j];
				int yn = 2 * n;
				adj[yn].push_back(4 * turret_count + 1 - yn);
				rev[4 * turret_count + 1 - yn].push_back(yn);
			}else{
				int n = turret[i2][j];
				int yn = 2 * n;
				adj[4 * turret_count + 1 - yn].push_back(yn);
				rev[yn].push_back(4 * turret_count + 1 - yn);
			}
		}
	}
	vector<bool> visited(4 * turret_count + 1);
	vector<int> post_order;
	for(int a = 1; a <= 4 * turret_count; ++a){
		traverse(post_order, adj, visited, a);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(4 * turret_count + 1, -1);
	int comp = 0;
	for(int b : post_order){
		if(assigned[b] == -1){
			++comp;
			assign(rev, assigned, b, comp);
		}
	}
	vector<int> dir(turret_count + 1);
	for(int n = 1; n <= turret_count; ++n){
		int xn = 2 * n - 1, yn = 2 * n;
		if(assigned[xn] > assigned[4 * turret_count + 1 - xn] && assigned[yn] > assigned[4 * turret_count + 1 - yn]){
			dir[n] = 2;
		}else if(assigned[xn] > assigned[4 * turret_count + 1 - xn]){
			dir[n] = 3;
		}else if(assigned[yn] > assigned[4 * turret_count + 1 - yn]){
			dir[n] = 1;
		}else{
			dir[n] = 4;
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < s; ++j){
			if(map[i][j] == 'T'){
				int n = turret[i][j];
				printf("%d", dir[n]);
			}else{
				printf("%c", map[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
