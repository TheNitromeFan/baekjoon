#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

bool bipartite_match(vector<vector<int>> &adj, vector<int> &matched, vector<bool> &visited, int u){
	for(int v : adj[u]){
		if(!visited[v]){
			visited[v] = true;
			if(matched[v] == -1 || bipartite_match(adj, matched, visited, matched[v])){
				matched[v] = u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	bool board[MAX][MAX] = {};
	for(int a0 = 0; a0 < m; ++a0){
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = true;
	}
	int diag1 = 0, diag2 = 0;
	int checked1[MAX][MAX] = {}, checked2[MAX][MAX] = {};
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < n; ++y){
			if(board[x][y]){
				continue;
			}
			if(!checked1[x][y]){
				++diag1;
				checked1[x][y] = diag1;
				int nx = x;
				int ny = y;
				while(true){
					++nx;
					++ny;
					if(!(nx >= 0 && nx < n && ny >= 0 && ny < n && !board[nx][ny])){
						break;
					}
					checked1[nx][ny] = diag1;
				}
			}
			if(!checked2[x][y]){
				++diag2;
				checked2[x][y] = diag2;
				int nx = x;
				int ny = y;
				while(true){
					++nx;
					--ny;
					if(!(nx >= 0 && nx < n && ny >= 0 && ny < n && !board[nx][ny])){
						break;
					}
					checked2[nx][ny] = diag2;
				}
			}
		}
	}
	vector<vector<int>> adj(diag1 + diag2 + 1);
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < n; ++y){
			if(!board[x][y]){
				int val1 = checked1[x][y];
				int val2 = checked2[x][y];
				adj[val1].push_back(val2 + diag1);
				adj[val2 + diag1].push_back(val1);
			}
		}
	}
	vector<int> matched(diag1 + diag2 + 1, -1);
	int matchable = 0;
	for(int u = 1; u <= diag1 + diag2; ++u){
		vector<bool> visited(diag1 + diag2 + 1);
		if(bipartite_match(adj, matched, visited, u)){
			++matchable;
		}
	}
	cout << matchable / 2 << '\n';
	return 0;
}
