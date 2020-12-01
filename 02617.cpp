#include <iostream>

using namespace std;

void floyd_warshall(bool adj[][101], int n){
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
	bool adj1[101][101] = {}, adj2[101][101] = {};
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj1[u][v] = true;
		adj2[v][u] = true;
	}
	floyd_warshall(adj1, n);
	floyd_warshall(adj2, n);
	int ans = 0;
	for(int u = 1; u <= n; ++u){
		int cnt1 = 0, cnt2 = 0;
		for(int v = 1; v <= n; ++v){
			if(v == u){
				continue;
			}
			if(adj1[u][v]){
				++cnt1;
			}
			if(adj2[u][v]){
				++cnt2;
			}
		}
		if(cnt1 > (n - 1) / 2 || cnt2 > (n - 1) / 2){
			// printf("%d\n", u);
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
