#include <cstdio>
#define MOD 1000000000

int main(){
	int n;
	scanf("%d", &n);
	static int a[1000001][20] = {};
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j < 20; ++j){
			if(i == 0 || j == 0){
				a[i][j] = 1;
			}else if((1 << j) <= i){
				a[i][j] = (a[i][j - 1] + a[i - (1 << j)][j]) % MOD;
			}else{
				a[i][j] = a[i][j - 1];
			}
		}
	}
	printf("%d", a[n][19]);
	return 0;
}
