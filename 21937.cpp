#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int n, int u, int &cnt){
	++cnt;
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(adj, visited, n, v, cnt);
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
		adj[v].push_back(u);
	}
	int x;
	cin >> x;
	vector<bool> visited(n + 1);
	int ans = 0;
	dfs(adj, visited, n, x, ans);
	--ans;
	cout << ans << '\n';
	return 0;
}
