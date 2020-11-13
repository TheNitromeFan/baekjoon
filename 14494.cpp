#include <cstdio>
#define MOD 1000000007

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int a[1001][1001] = {};
	a[1][1] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(i == 1 && j == 1){
				continue;
			}else if(i == 1){
				a[1][j] = a[i][j-1];
			}else if(j == 1){
				a[i][1] = a[i-1][j];
			}else{
				a[i][j] = ((a[i-1][j-1] + a[i][j-1]) % MOD + a[i-1][j]) % MOD;
			}
		}
	}
	printf("%d", a[n][m]);
	return 0;
}
