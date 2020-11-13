#include <cstdio>
#include <algorithm>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int map[1001][1001] = {}, prefix[1001][1001] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &map[i][j]);
			prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + map[i][j];
		}
	}
	static int dp[1001][1001][2] = {};
	for(int i = 2; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			dp[i][j][0] = prefix[i-1][j] + map[i][j];
			dp[i][j][1] = prefix[i-1][j] + map[i][j];
		}
		for(int j = 2; j <= m; ++j){
			if(dp[i][j-1][0] + map[i][j] > dp[i][j][0]){
				dp[i][j][0] = dp[i][j-1][0] + map[i][j];
			}
		}
		for(int j = m-1; j >= 1; --j){
			if(dp[i][j+1][1] + map[i][j] > dp[i][j][1]){
				dp[i][j][1] = dp[i][j+1][1] + map[i][j];
			}
		}
		for(int j = 1; j <= m; ++j){
			prefix[i][j] = std::max(dp[i][j][0], dp[i][j][1]);
		}
	}
	printf("%d", prefix[n][m]);
	return 0;
}
