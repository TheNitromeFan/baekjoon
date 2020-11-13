#include <cstdio>

int main(){
	long long comb[31][31] = {};
	for(int n = 1; n <= 30; ++n){
		for(int j = 1; j <= n; ++j){
			if(j == 1 || j == n){
				comb[n][j] = 1;
			}else{
				comb[n][j] = comb[n - 1][j - 1] + comb[n - 1][j];
			}
		}
	}
	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);
	long long sum = 0;
	for(int i = 1, n = r; i <= w; ++i, ++n){
		for(int k = 1, j = c; k <= i; ++k, ++j){
			sum += comb[n][j];
		}
	}
	printf("%lld", sum);
	return 0;
}
