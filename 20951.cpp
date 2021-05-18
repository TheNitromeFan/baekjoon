#include <iostream>
#include <vector>
#define MAX 100001
#define MOD 1000000007

using namespace std;

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
	long long dp[9][MAX] = {};
	for(int j = 1; j <= n; ++j){
		dp[1][j] = 1;
	}
	for(int i = 2; i <= 8; ++i){
		for(int j = 1; j <= n; ++j){
			for(int v : adj[j]){
				dp[i][j] += dp[i - 1][v];
				dp[i][j] %= MOD;
			}
			// cout << dp[i][j] << ' ';
		}
		// cout << '\n';
	}
	long long sum = 0;
	for(int j = 1; j <= n; ++j){
		sum += dp[8][j];
		sum %= MOD;
	}
	cout << sum;
	return 0;
}
