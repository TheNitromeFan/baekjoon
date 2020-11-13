#include <cstdio>
#define MAX 100

int main(){
	int t;
	scanf("%d", &t);
	int dp[MAX + 1][MAX + 1][2] = {}; // dp[i][j][k]: i bits, j adjacent, last bit k
	// dp[n][k][0] = dp[n - 1][k][0] + dp[n - 1][k][1]
	// dp[n][k][1] = dp[n - 1][k - 1][1] + dp[n - 1][k][0]
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for(int n = 2; n <= MAX; ++n){
		for(int k = 0; k <= MAX; ++k){
			dp[n][k][0] = dp[n - 1][k][0] + dp[n - 1][k][1];
			dp[n][k][1] = dp[n - 1][k][0];
			if(k > 0){
				dp[n][k][1] += dp[n - 1][k - 1][1];
			}
		}
	}
	for(int i = 0; i < t; ++i){
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", dp[n][k][0] + dp[n][k][1]);
	}
	return 0;
}
