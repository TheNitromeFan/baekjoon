#include <cstdio>
#include <vector>
#define MAX 101

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
	int n;
	scanf("%d", &n);
	char board[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	int checked1[MAX][MAX] = {}, checked2[MAX][MAX] = {};
	int row = 0, col = 0;
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < n; ++y){
			if(board[x][y] == 'X'){
				continue;
			}
			if(!checked1[x][y]){
				++row;
				int nx = x;
				int ny = y;
				while(nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == '.'){
					checked1[nx][ny] = row;
					++ny;
				}
			}
			if(!checked2[x][y]){
				++col;
				int nx = x;
				int ny = y;
				while(nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == '.'){
					checked2[nx][ny] = col;
					++nx;
				}
			}
		}
	}
	vector<vector<int>> adj(row + col + 1);
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < n; ++y){
			if(board[x][y] == '.'){
				int r = checked1[x][y], c = checked2[x][y];
				adj[r].push_back(c + row);
				adj[c + row].push_back(r);
			}
		}
	}
	vector<int> matched(row + col + 1, -1);
	int ans = 0;
	for(int r = 1; r <= row; ++r){
		vector<bool> visited(row + col + 1);
		if(bipartite_matching(adj, matched, visited, r)){
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
