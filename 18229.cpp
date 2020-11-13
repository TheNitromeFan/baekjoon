#include <cstdio>

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int a[101][101];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	int reach[101] = {};
	for(int j = 1; j <= m; ++j){
		for(int i = 1; i <= n; ++i){
			reach[i] += a[i][j];
			if(reach[i] >= k){
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	return 0;
}
