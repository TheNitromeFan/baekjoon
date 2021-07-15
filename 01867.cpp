#include <iostream>
#include <vector>
#define MAX 501

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
	int n, k;
	cin >> n >> k;
	bool board[MAX][MAX] = {};
	for(int i = 0; i < k; ++i){
		int x, y;
		cin >> x >> y;
		board[x][y] = true;
	}
	vector<vector<int>> adj(2 * n + 1);
	for(int x = 1; x <= n; ++x){
		for(int y = 1; y <= n; ++y){
			if(board[x][y]){
				adj[x].push_back(y + n);
				adj[y + n].push_back(x);
			}
		}
	}
	int ans = 0;
	vector<int> matched(2 * n + 1, -1);
	for(int x = 1; x <= n; ++x){
		vector<bool> visited(2 * n + 1);
		if(bipartite_matching(adj, matched, visited, x)){
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
