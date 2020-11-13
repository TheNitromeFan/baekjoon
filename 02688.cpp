#include <cstdio>
#define MAX 64

int main(){
	int p;
	scanf("%d", &p);
	long long dp[MAX + 1][10] = {}; // dp[i][j]: # of i-digit numbers ending in j
	for(int j = 0; j < 10; ++j){
		dp[1][j] = 1;
	}
	for(int a0 = 0; a0 < p; ++a0){
		int n;
		scanf("%d", &n);
		long long ans = 0;
		if(dp[n][0] > 0){
			for(int j = 0; j < 10; ++j){
				ans += dp[n][j];
			}
			printf("%lld\n", ans);
			continue;
		}
		for(int i = 1; i <= n; ++i){
			if(dp[i][0] > 0){
				continue;
			}
			for(int j = 0; j < 10; ++j){
				for(int k = 0; k <= j; ++k){
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
		for(int j = 0; j < 10; ++j){
			ans += dp[n][j];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
