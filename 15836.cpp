#include <cstdio>

int main(){
	int t = 0;
	while(true){
		int m, n, p, q;
		scanf("%d %d %d %d", &m, &n, &p, &q);
		if(m == 0 && n == 0 && p == 0 && q == 0){
			break;
		}
		++t;
		int a[21][21], b[21][21];
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= n; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		for(int i = 1; i <= p; ++i){
			for(int j = 1; j <= q; ++j){
				scanf("%d", &b[i][j]);
			}
		}
		printf("Case #%d:\n", t);
		if(n != p){
			printf("undefined\n");
			continue;
		}
		int c[21][21] = {};
		for(int i = 1; i <= m; ++i){
			printf("| ");
			for(int j = 1; j <= q; ++j){
				for(int k = 1; k <= n; ++k){
					c[i][j] += a[i][k] * b[k][j];
				}
				printf("%d ", c[i][j]);
			}
			printf("|\n");
		}
	}
	return 0;
}
