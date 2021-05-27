#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 100010

using namespace std;

bool visited[MAX];
int depth[MAX], dist[MAX];
int dp[MAX][20];
vector<int> adj[MAX];

void dfs(int u, int d, int c){
	visited[u] = true;
	depth[u] = d;
	dist[u] = c;
	for(int v : adj[u]){
		if(!visited[v]){
			dp[v][0] = u;
			dfs(v, d + 1, c + 1);
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


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
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
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
	return 0;
}
