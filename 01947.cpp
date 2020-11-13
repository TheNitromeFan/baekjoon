#include <cstdio>
#define MAX (1000000 + 1)
#define MOD 1000000000

int main(){
	static long long dp[MAX];
	dp[0] = 1;
	dp[1] = 0;
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
	}
	printf("%lld", dp[n]);
	return 0;
}
