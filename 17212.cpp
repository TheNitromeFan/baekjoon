#include <cstdio>
#define MAX (100000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	int dp[MAX];
	dp[0] = 0;
	for(int i = 1; i <= n; ++i){
		dp[i] = dp[i - 1] + 1;
		if(i >= 2 && dp[i] > dp[i - 2] + 1){
			dp[i] = dp[i - 2] + 1;
		}
		if(i >= 5 && dp[i] > dp[i - 5] + 1){
			dp[i] = dp[i - 5] + 1;
		}
		if(i >= 7 && dp[i] > dp[i - 7] + 1){
			dp[i] = dp[i - 7] + 1;
		}
	}
	printf("%d", dp[n]);
	return 0;
}
