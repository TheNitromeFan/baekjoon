#include <cstdio>
#define MAX (33333 + 1)
#define MOD 1000000009

int main(){
	int n;
	scanf("%d", &n);
	int dp[MAX][3] = {}; // dp[i][j]: i digits, remainder j
	dp[1][1] = 1;
	dp[1][2] = 1;
	for(int i = 2; i <= n; ++i){
		dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) % MOD + dp[i - 1][2]) % MOD;
		dp[i][1] = ((dp[i - 1][0] + dp[i - 1][1]) % MOD + dp[i - 1][2]) % MOD;
		dp[i][2] = ((dp[i - 1][0] + dp[i - 1][1]) % MOD + dp[i - 1][2]) % MOD;
	}
	printf("%d", dp[n][0]);
	return 0;
}
