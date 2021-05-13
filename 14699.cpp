#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> h(n + 1), order(n);
	for(int u = 1; u <= n; ++u){
		cin >> h[u];
		order[u - 1] = u;
	}
	sort(order.begin(), order.end(), [&h](int u, int v){
		return h[u] > h[v];
	});
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		if(h[u] < h[v]){
			adj[u].push_back(v);
		}else{
			adj[v].push_back(u);
		}
	}
	vector<int> dp(n + 1);
	for(int u : order){
		int cmp = 0;
		for(int v : adj[u]){
			cmp = max(cmp, dp[v]);
		}
		dp[u] = cmp + 1;
	}
	for(int u = 1; u <= n; ++u){
		cout << dp[u] << '\n';
	}
	return 0;
}
