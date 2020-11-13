#include <cstdio>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);
	int p[1001];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &p[i]);
	}
	int dp[1001] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= i; ++j){
			dp[i] = std::max(dp[i], dp[i-j] + p[j]);
		}
	}
	printf("%d", dp[n]);
	return 0;
}
