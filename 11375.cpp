#include <iostream>
#include <vector>

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
	vector<vector<int>> adj(n + m + 1);
	for(int u = 1; u <= n; ++u){
		int t;
		cin >> t;
		for(int i = 0; i < t; ++i){
			int v;
			cin >> v;
			adj[u].push_back(v + n);
			adj[v + n].push_back(u);
		}
	}
	vector<int> matched(n + m + 1, -1);
	int ans = 0;
	for(int u = 1; u <= n; ++u){
		vector<bool> visited(n + m + 1);
		if(bipartite_match(adj, matched, visited, u)){
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
