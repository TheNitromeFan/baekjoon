#include <cstdio>
#define MAX (1000 + 1)
#define MOD 1000000

int main(){
	int n;
	scanf("%d", &n);
	int dp[MAX][2][3] = {}; // days, lates, consec. absences
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; ++i){
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
		dp[i][0][1] = dp[i - 1][0][0];
		dp[i][0][2] = dp[i - 1][0][1];
		dp[i][1][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]
		+ dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
		dp[i][1][1] = dp[i - 1][1][0];
		dp[i][1][2] = dp[i - 1][1][1];
	}
	printf("%d", (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] +
	dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % MOD);
	return 0;
}
