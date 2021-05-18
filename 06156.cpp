#include <iostream>
#define MAX 101

using namespace std;

void floyd_warshall(bool adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(adj[i][k] && adj[k][j]){
					adj[i][j] = true;
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
	bool adj[MAX][MAX] = {}, rev[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u][v] = true;
		rev[v][u] = true;
	}
	floyd_warshall(adj, n);
	floyd_warshall(rev, n);
	int ans = 0;
	for(int u = 1; u <= n; ++u){
		int cnt = 0;
		for(int v = 1; v <= n; ++v){
			if(v == u){
				continue;
			}
			if(adj[u][v] || rev[u][v]){
				++cnt;
			}
		}
		if(cnt == n - 1){
			++ans;
		}
	}
	cout << ans;
	return 0;
}
