#include <iostream>
#include <algorithm>
#define MAX 201
#define MAXVAL 1000000000000000000LL

using namespace std;

void floyd_warshall(long long adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	long long adj[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i != j){
				adj[i][j] = MAXVAL;
			}else{
				adj[i][j] = 0;
			}
		}
	}
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		adj[u][v] = min(adj[u][v], w);
	}
	floyd_warshall(adj, n);
	int cnt = 0;
	long long sum_cost = 0;
	for(int a1 = 0; a1 < q; ++a1){
		int a, b;
		cin >> a >> b;
		long long cost = MAXVAL;
		for(int v = 1; v <= k; ++v){
			cost = min(cost, adj[a][v] + adj[v][b]);
		}
		if(cost != MAXVAL){
			++cnt;
			sum_cost += cost;
		}
	}
	cout << cnt << '\n' << sum_cost;
	return 0;
}
