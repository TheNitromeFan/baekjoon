#include <cstdio>
#define MAX (5000 + 1)
#define MOD 1000000007

int main(){
	int t;
	scanf("%d", &t);
	long long dp[MAX] = {};
	dp[0] = 1;
	dp[2] = 1;
	for(int idx = 3; idx < MAX; ++idx){
		for(int j = 2; j <= idx; ++j){
			dp[idx] += dp[j - 2] * dp[idx - j];
			dp[idx] %= MOD;
		}
	}
	for(int a0 = 0; a0 < t; ++a0){
		int len;
		scanf("%d", &len);
		printf("%lld\n", dp[len]);
	}
	return 0;
}
