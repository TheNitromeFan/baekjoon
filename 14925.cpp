#include <cstdio>
#include <algorithm>
#define MAX 1000

int main(){
	int n, m;
	static int ranch[MAX + 1][MAX + 1];
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &ranch[i][j]);
		}
	}
	static int dp[MAX + 1][MAX + 1] = {};
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(ranch[i][j] != 0){
				continue;
			}
			if(dp[i - 1][j] != dp[i][j - 1]){
				dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
			}else if(ranch[i - dp[i - 1][j]][j - dp[i - 1][j]] == 0){
				dp[i][j] = dp[i - 1][j] + 1;
			}else{
				dp[i][j] = dp[i - 1][j];
			}
			if(dp[i][j] > ans){
				ans = dp[i][j];
			}
		}
	}
	printf("%d", ans);
	return 0;
}
