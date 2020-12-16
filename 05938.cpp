#include <iostream>
#include <vector>

using namespace std;

void visit(vector<vector<int>> &adj, int n, vector<bool> &visited, int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			visit(adj, n, visited, v);
		}
	}
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
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> visited(n + 1);
	visit(adj, n, visited, 1);
	vector<int> ans;
	for(int u = 1; u <= n; ++u){
		if(!visited[u]){
			ans.push_back(u);
		}
	}
	if(!ans.empty()){
		for(int v : ans){
			cout << v << "\n";
		}
	}else{
		cout << 0;
	}
	return 0;
}
