#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

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

bool satisfiable(vector<vector<int>> &adj, vector<vector<int>> &rev, int n, int m){
	vector<bool> visited(2 * (n + m));
	vector<int> post_order;
	for(int u = 0; u < 2 * (n + m); ++u){
		traverse(post_order, adj, visited, u);
	}
	reverse(post_order.begin(), post_order.end());
	vector<int> assigned(2 * (n + m), -1);
	int comp = 0;
	for(int v : post_order){
		if(assigned[v] == -1){
			++comp;
			assign(rev, assigned, v, comp);
		}
	}
	for(int u = 0; u < n + m; ++u){
		if(assigned[u] == assigned[2 * (n + m) - 1 - u]){
			return false;
		}
	}
	return true;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	vector<vector<int>> adj(2 * (n + m)), rev(2 * (n + m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] == '*'){
				int x = i, y = j + n;
				adj[x].push_back(2 * (n + m) - 1 - y);
				rev[2 * (n + m) - 1 - y].push_back(x);
				adj[y].push_back(2 * (n + m) - 1 - x);
				rev[2 * (n + m) - 1 - x].push_back(y);
				adj[2 * (n + m) - 1 - x].push_back(y);
				rev[y].push_back(2 * (n + m) - 1 - x);
				adj[2 * (n + m) - 1 - y].push_back(x);
				rev[x].push_back(2 * (n + m) - 1 - y);
			}else if(map[i][j] == '#'){
				int x = i, y = j + n;
				adj[2 * (n + m) - 1 - x].push_back(2 * (n + m) - 1 - y);
				rev[2 * (n + m) - 1 - y].push_back(2 * (n + m) - 1 - x);
				adj[y].push_back(x);
				rev[x].push_back(y);
				adj[x].push_back(y);
				rev[y].push_back(x);
				adj[2 * (n + m) - 1 - y].push_back(2 * (n + m) - 1 - x);
				rev[2 * (n + m) - 1 - x].push_back(2 * (n + m) - 1 - y);
			}
		}
	}
	printf("%d\n", satisfiable(adj, rev, n, m));
	return 0;
}
