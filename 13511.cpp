#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 100010

using namespace std;

bool visited[MAX];
int depth[MAX];
long long dist[MAX];
int dp[MAX][20];
vector<pair<int, long long>> adj[MAX];

void dfs(int u, int d, long long c){
	visited[u] = true;
	depth[u] = d;
	dist[u] = c;
	for(pair<int, long long > p : adj[u]){
		int v = p.first;
		long long w = p.second;
		if(!visited[v]){
			dp[v][0] = u;
			dfs(v, d + 1, c + w);
		}
	}
}

int lca(int u, int v){
	if(depth[u] > depth[v]){
		swap(u, v);
	}
	int d = depth[v] - depth[u];
	for(int i = 0; d; ++i){
		if(d % 2 == 1){
			v = dp[v][i];
		}
		d /= 2;
	}
	if(u == v){
		return u;
	}
	for(int i = 19; i >= 0; --i){
		if(dp[u][i] != dp[v][i]){
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[u][0];
}

int kth(int u, int v, int k){
	int w = lca(u, v);
	int d = depth[u] - depth[w];
	--k;
	if(d < k){
		k = depth[v] - depth[w] + d - k;
		for(int i = 0; k; ++i){
			if(k % 2 == 1){
				v = dp[v][i];
			}
			k /= 2;
		}
		return v;
	}else{
		for(int i = 0; k; ++i){
			if(k % 2 == 1){
				u = dp[u][i];
			}
			k /= 2;
		}
		return u;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	dfs(1, 0, 0);
	for(int j = 1; j < 20; ++j){
		for(int u = 1; u <= n; ++u){
			dp[u][j] = dp[dp[u][j - 1]][j - 1];
		}
	}
	int m;
	cin >> m;
	for(int a0 = 0; a0 < m; ++a0){
		int q;
		cin >> q;
		if(q == 1){
			int u, v;
			cin >> u >> v;
			cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << '\n';
		}else{
			int u, v, k;
			cin >> u >> v >> k;
			cout << kth(u, v, k) << '\n';
		}
	}
	return 0;
}
