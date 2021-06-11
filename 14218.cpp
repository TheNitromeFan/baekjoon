#include <iostream>
#include <cstring>
#include <vector>
#define MAX 1001

using namespace std;

int dp[MAX];

void dfs(vector<vector<int>> &adj, int u, int val){
	dp[u] = val;
	for(int v : adj[u]){
		if(dp[v] == -1 || dp[v] > val + 1){
			dfs(adj, v, val + 1);
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
	memset(dp, -1, sizeof(dp));
	dfs(adj, 1, 0);
	int q;
	cin >> q;
	for(int j = 0; j < q; ++j){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(dp[v] != -1 && (dp[u] == -1 || dp[u] > dp[v] + 1)){
			dfs(adj, u, dp[v] + 1);
		}else if(dp[u] != -1 && (dp[v] == -1 || dp[v] > dp[u] + 1)){
			dfs(adj, v, dp[u] + 1);
		}
		for(int city = 1; city <= n; ++city){
			cout << dp[city] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
