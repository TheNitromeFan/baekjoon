#include <iostream>
#define MAX 201
#define MAXVAL 4000000000000000000LL

using namespace std;

void floyd_warshall(long long adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj[i][j] > adj[i][k] + adj[k][j]){
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	long long adj[MAX][MAX] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i != j){
				adj[i][j] = MAXVAL;
			}
		}
	}
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		if(adj[u][v] > w){
			adj[u][v] = w;
			adj[v][u] = w;
		}
	}
	floyd_warshall(adj, n);
	int ans = -1;
	long long min_sum = MAXVAL;
	for(int u = 1; u <= n; ++u){
		long long sum = 0;
		for(int v = 1; v <= n; ++v){
			sum += adj[u][v];
		}
		// cout << u << ' ' << sum << '\n';
		if(sum < min_sum){
			ans = u;
			min_sum = sum;
		}
	}
	cout << ans;
	return 0;
}
