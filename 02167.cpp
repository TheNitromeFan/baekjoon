#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[301][301] = {}, pre[301][301] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &a[i][j]);
			pre[i][j] = pre[i-1][j] - pre[i-1][j-1] + pre[i][j-1]  + a[i][j];
		}
	}
	int k;
	scanf("%d", &k);
	for(int q = 0; q < k; ++q){
		int i, j, x, y;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		printf("%d\n", pre[x][y] - pre[i-1][y] - pre[x][j-1] + pre[i-1][j-1]);
	}
	return 0;
}
