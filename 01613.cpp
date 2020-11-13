#include <cstdio>
#define MAX (400 + 1)

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

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	bool adj[MAX][MAX] = {};
	for(int i = 0; i < k; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u][v] = true;
	}
	floyd_warshall(adj, n);
	int s;
	scanf("%d", &s);
	for(int j = 0; j < s; ++j){
		int u, v;
		scanf("%d %d", &u, &v);
		if(adj[u][v]){
			printf("-1");
		}else if(adj[v][u]){
			printf("1");
		}else{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
