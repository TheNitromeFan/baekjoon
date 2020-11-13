#include <cstdio>
#define MAX (100000 + 1)
#define MOD 16769023

int main(){
	int n;
	scanf("%d", &n);
	int dp[MAX][3];
	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[1][2] = 1;
	for(int i = 2; i <= n; ++i){
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = dp[i - 1][1];
	}
	printf("%d", (dp[n][0] + dp[n][1] + dp[n][2]) % MOD);
	return 0;
}
