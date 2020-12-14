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
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		if(u % 2 != v % 2){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	int ans = 0;
	vector<int> matched(n + 1, -1);
	for(int u = 1; u <= n; u += 2){
		vector<bool> visited(n + 1);
		if(bipartite_match(adj, matched, visited, u)){
			++ans;
		}
	}
	ans *= 2;
	if(ans < n){
		++ans;
	}
	cout << ans;
	return 0;
}
