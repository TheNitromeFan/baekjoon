#include <cstdio>
#define MAX (500 + 1)

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

bool can_compare(bool adj[][MAX], int n, int x){
	for(int i = 1; i <= n; ++i){
		if(i != x && !adj[i][x] && !adj[x][i]){
			return false;
		}
	}
	return true;
}

int can_compare_cnt(bool adj[][MAX], int n){
	int ret = 0;
	for(int i = 1; i <= n; ++i){
		if(can_compare(adj, n, i)){
			++ret;
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bool adj[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = true;
	}
	floyd_warshall(adj, n);
	printf("%d", can_compare_cnt(adj, n));
	return 0;
}
