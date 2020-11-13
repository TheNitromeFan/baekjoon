#include <cstdio>
#include <cstring>
#define MAX (250 + 1)

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
	int n, m;
	scanf("%d %d", &n, &m);
	int adj[MAX][MAX];
	memset(adj, -1, sizeof(adj));
	for(int i = 1; i <= n; ++i){
		adj[i][i] = 0;
	}
	for(int i = 0; i < m; ++i){
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);
		adj[u][v] = 0;
		if(b){
			adj[v][u] = 0;
		}else{
			adj[v][u] = 1;
		}
	}
	floyd_warshall(adj, n);
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", adj[s][e]);
	}
	return 0;
}
