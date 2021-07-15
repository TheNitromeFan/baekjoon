#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &adj, vector<int> &visited, int u, int c){
	visited[u] = c;
	for(int v : adj[u]){
		if(visited[v] == c || (visited[v] == -1 && !dfs(adj, visited, v, 1 - c))){
			return false;
		}
	}
	return true;
}

bool is_bipartite(vector<vector<int>> &adj, int n){
	vector<int> visited(n + 1, -1);
	for(int u = 1; u <= n; ++u){
		if(visited[u] == -1 && !dfs(adj, visited, u, 0)){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		for(int a1 = 0; a1 < m; ++a1){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << "Scenario #" << a0 << ":\n";
		if(is_bipartite(adj, n)){
			cout << "No suspicious bugs found!\n\n";
		}else{
			cout << "Suspicious bugs found!\n\n";
		}
	}
	return 0;
}
