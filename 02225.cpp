#include <cstdio>
#define MOD 1000000000

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int dp[201][201] = {}; // dp[i][j]: add up to i using j numbers
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= k; ++j){
			if(j == 0){
				continue;
			}
			if(i == 0){
				dp[0][j] = 1;
			}else{
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
			}
		}
	}
	printf("%d", dp[n][k]);
	return 0;
}
