#include <cstdio>

int main(){
	int c[9][9] = {};
	c[0][0] = 1;
	for(int n = 1; n <= 8; ++n){
		for(int k = 0; k <= n; ++k){
			if(k == 0 || k == n){
				c[n][k] = 1;
			}else{
				c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
			}
		}
	}
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int event = 0;
	for(int j = k; j <= m; ++j){
		event += c[m][j] * c[n - m][m - j];
	}
	printf("%.10f", event / (double)c[n][m]);
	return 0;
}
