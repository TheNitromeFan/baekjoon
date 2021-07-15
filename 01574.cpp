#include <iostream>
#include <vector>
#define MAX 301

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c, n;
	cin >> r >> c >> n;
	bool board[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		board[x][y] = true;
	}
	vector<vector<int>> adj(r + c + 1);
	for(int x = 1; x <= r; ++x){
		for(int y = 1; y <= c; ++y){
			if(!board[x][y]){
				adj[x].push_back(y + r);
				adj[y + r].push_back(x);
			}
		}
	}
	int ans = 0;
	vector<int> matched(r + c + 1, -1);
	for(int x = 1; x <= r; ++x){
		vector<bool> visited(r + c + 1);
		if(bipartite_matching(adj, matched, visited, x)){
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
