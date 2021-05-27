#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 100010

using namespace std;

bool visited[MAX];
int depth[MAX], dist[MAX];
int dp[MAX][22], mini[MAX][22], maxi[MAX][22];
vector<pair<int, int>> adj[MAX];

void dfs(int u, int d, int c){
	visited[u] = true;
	depth[u] = d;
	dist[u] = c;
	for(pair<int, int> p : adj[u]){
		int v = p.first, cost = p.second;
		if(!visited[v]){
			dp[v][0] = u;
			mini[v][0] = cost;
			maxi[v][0] = cost;
			dfs(v, d + 1, c + cost);
		}
	}
}

pair<int, int> lca(int u, int v){
	int low = 2000000000, high = -2000000000;
	if(depth[u] > depth[v]){
		swap(u, v);
	}
	int d = depth[v] - depth[u];
	for(int i = 0; d; ++i){
		if(d % 2 == 1){
			low = min(low, mini[v][i]);
			high = max(high, maxi[v][i]);
			v = dp[v][i];
		}
		d /= 2;
	}
	if(u == v){
		return make_pair(low, high);
	}
	for(int i = 21; i >= 0; --i){
		if(dp[u][i] != dp[v][i]){
			low = min(low, min(mini[u][i], mini[v][i]));
			high = max(high, max(maxi[u][i], maxi[v][i]));
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	low = min(low, min(mini[u][0], mini[v][0]));
	high = max(high, max(maxi[u][0], maxi[v][0]));
	return make_pair(low, high);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	dfs(1, 0, 0);
	for(int j = 1; j < 22; ++j){
		for(int u = 1; u <= n; ++u){
			dp[u][j] = dp[dp[u][j - 1]][j - 1];
			mini[u][j] = min(mini[u][j - 1], mini[dp[u][j  - 1]][j - 1]);
			maxi[u][j] = max(maxi[u][j - 1], maxi[dp[u][j  - 1]][j - 1]);
		}
	}
	int k;
	cin >> k;
	for(int a0 = 0; a0 < k; ++a0){
		int d, e;
		cin >> d >> e;
		pair<int, int> ans = lca(d, e);
		cout << ans.first << ' ' << ans.second << '\n';
	}
	return 0;
}
