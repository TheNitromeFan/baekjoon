#include <cstdio>
#define MAX 100000000

int dist[1001][1001];

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

int max_dist(int n, int x){
	solve(n);
	int ret = 0;
	for(int i = 1; i <= n; ++i){
		if(dist[i][x] + dist[x][i] > ret){
			ret = dist[i][x] + dist[x][i];
		}
	}
	return ret;
}

int main(){
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i == j){
				dist[i][j] = 0;
			}else{
				dist[i][j] = MAX;
			}
		}
	}
	for(int e = 0; e < m; ++e){
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		dist[a][b] = t;
	}
	printf("%d", max_dist(n, x));
	return 0;
}
