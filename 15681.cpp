#include <iostream>
#include <vector>

using namespace std;

int dp(vector<vector<int>> &adj, vector<int> &children, vector<bool> &visited, int n, int u){
	if(visited[u]){
		return 0;
	}
	if(children[u] != -1){
		return children[u];
	}
	visited[u] = true;
	children[u] = 1;
	for(int v : adj[u]){
		children[u] += dp(adj, children, visited, n, v);
	}
	return children[u];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r, q;
	cin >> n >> r >> q;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> children(n + 1, -1);
	vector<bool> visited(n + 1);
	dp(adj, children, visited, n, r);
	for(int j = 0; j < q; ++j){
		int u;
		cin >> u;
		cout << children[u] << '\n';
	}
	return 0;
}
