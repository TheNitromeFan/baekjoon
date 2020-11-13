#include <cstdio>

bool adj[101][101];

int dist[101][101];

void solve(int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int bacon(int n, int u){
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += dist[u][i];
	}
	return ans;
}

int min_bacon(int n){
	solve(n);
	int ret = 0, min_so_far = 10000;
	for(int i = 1; i <= n; ++i){
		int tmp = bacon(n, i);
		if(tmp < min_so_far){
			ret = i;
			min_so_far = tmp;
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int e = 0; e < m; ++e){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u][v] = true;
		adj[v][u] = true;
	}
	for(int u = 1; u <= n; ++u){
		for(int v = 1; v <= n; ++v){
			if(u == v){
				dist[u][v] = 0;
			}else if(adj[u][v]){
				dist[u][v] = 1;
			}else{
				dist[u][v] = 10000;
			}
		}
	}
	printf("%d", min_bacon(n));
	return 0;
}
