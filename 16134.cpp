#include <cstdio>
#define MOD 1000000007

int main(){
	int n, r;
	scanf("%d %d", &n, &r);
	static int c[1001][1001];
	c[0][0] = 1;
	c[1][0] = 1;
	c[1][1] = 1;
	for(int i = 2; i <= n; ++i){
		for(int k = 0; k <= i; ++k){
			if(k == 0 || k == i){
				c[i][k] = 1;
			}else{
				c[i][k] = (c[i-1][k-1] + c[i-1][k]) % MOD;
			}
		}
	}
	printf("%d", c[n][r]);
	return 0;
}
