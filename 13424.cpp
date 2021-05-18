#include <iostream>
#include <vector>
#include <cstring>
#define MAX 101

using namespace std;

void floyd_warshall(int adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj[i][k] != -1 && adj[k][j] != -1 && (adj[i][j] == -1 || adj[i][j] > adj[i][k] + adj[k][j])){
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, m;
		cin >> n >> m;
		int adj[MAX][MAX];
		memset(adj, -1, sizeof(adj));
		for(int v = 1; v <= n; ++v){
			adj[v][v] = 0;
		}
		for(int i = 0; i < m; ++i){
			int u, v, w;
			cin >> u >> v >> w;
			adj[u][v] = w;
			adj[v][u] = w;
		}
		int k;
		cin >> k;
		vector<int> friends(k);
		for(int j = 0; j < k; ++j){
			cin >> friends[j];
		}
		floyd_warshall(adj, n);
		int ans = -1, min_dist = 2000000000;
		for(int u = 1; u <= n; ++u){
			int dist = 0;
			for(int f : friends){
				dist += adj[u][f];
			}
			// cout << u << ' ' << dist << '\n';
			if(dist < min_dist){
				ans = u;
				min_dist = dist;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
