#include <cstdio>
#include <cstring>
#define MAX (400 + 1)

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

int min_cycle_length(int adj[][MAX], int n){
	floyd_warshall(adj, n);
	int ret = -1;
	for(int i = 1; i <= n; ++i){
		if(adj[i][i] != -1 && (ret == -1 || ret > adj[i][i])){
			ret = adj[i][i];
		}
	}
	return ret;
}

int main(){
	int v, e;
	scanf("%d %d", &v, &e);
	int adj[MAX][MAX];
	memset(adj, -1, sizeof(adj));
	for(int i = 0; i < e; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = c;
	}
	printf("%d", min_cycle_length(adj, v));
	return 0;
}
