#include <cstdio>
#include <vector>
#define MAX 51

using namespace std;

bool bipartite_matching(vector<vector<int>> &adj, vector<int> &matched, vector<bool> &visited, int u){
	for(int v : adj[u]){
		if(!visited[v]){
			visited[v] = true;
			if(matched[v] == -1 || bipartite_matching(adj, matched, visited, matched[v])){
				matched[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char board[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", board[i]);
	}
	int checked1[MAX][MAX] = {}, checked2[MAX][MAX] = {};
	int row = 0, col = 0;
	for(int x = 0; x < r; ++x){
		for(int y = 0; y < c; ++y){
			if(board[x][y] == '.'){
				continue;
			}
			if(!checked1[x][y]){
				++row;
				int nx = x;
				int ny = y;
				while(nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == '*'){
					checked1[nx][ny] = row;
					++ny;
				}
			}
			if(!checked2[x][y]){
				++col;
				int nx = x;
				int ny = y;
				while(nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == '*'){
					checked2[nx][ny] = col;
					++nx;
				}
			}
		}
	}
	vector<vector<int>> adj(row + col + 1);
	for(int x = 0; x < r; ++x){
		for(int y = 0; y < c; ++y){
			if(board[x][y] == '*'){
				int val1 = checked1[x][y], val2 = checked2[x][y];
				adj[val1].push_back(val2 + row);
				adj[val2 + row].push_back(val1);
			}
		}
	}
	vector<int> matched(row + col + 1, -1);
	int ans = 0;
	for(int u = 1; u <= row; ++u){
		vector<bool> visited(row + col + 1);
		if(bipartite_matching(adj, matched, visited, u)){
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
