#include <cstdio>

bool neighbor(int a[][201], int n, int x, int y){
	for(int i = 1; i <= n; ++i){
		if(i == x || i == y){
			continue;
		}
		if(a[x][i] + a[i][y] == a[x][y]){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	int dist[201][201];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &dist[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = i + 1; j <= n; ++j){
			if(neighbor(dist, n, i, j)){
				printf("%d %d\n", i, j);
			}
		}
	}
	return 0;
}
