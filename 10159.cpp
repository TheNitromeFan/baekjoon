#include <cstdio>
#define MAX (100 + 1)

void floyd_warshall(bool adj[][MAX], int n){
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(!adj[i][j] && adj[i][k] && adj[k][j]){
					adj[i][j] = true;
				}
			}
		}
	}
}

int connected_cnt(bool adj[][MAX], int n, int u){
	int ret = 0;
	for(int v = 1; v <= n; ++v){
		if(adj[u][v] || adj[v][u]){
			++ret;
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bool adj[MAX][MAX] = {};
	for(int i = 1; i <= n; ++i){
		adj[i][i] = true;
	}
	for(int a0 = 0; a0 < m; ++a0){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u][v] = true;
	}
	floyd_warshall(adj, n);
	for(int i = 1; i <= n; ++i){
		printf("%d\n", n - connected_cnt(adj, n, i));
	}
	return 0;
}
