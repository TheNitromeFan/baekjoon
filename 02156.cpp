#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int wine[10001] = {};
	for(int i = 1; i <= n; ++i){
		scanf("%d", &wine[i]);
	}
	if(n == 1){
		printf("%d", wine[1]);
		return 0;
	}
	int dp[10001] = {}; // dp[n]: up to n-th glass
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for(int i = 3; i <= n; ++i){
		dp[i] = dp[i-1];
		int tmp = dp[i-2] + wine[i];
		if(tmp > dp[i]){
			dp[i] = tmp;
		}
		tmp = dp[i-3] + wine[i-1] + wine[i];
		if(tmp > dp[i]){
			dp[i] = tmp;
		}
	}
	printf("%d", dp[n]);
	return 0;
}
