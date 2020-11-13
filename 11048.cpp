#include <cstdio>
#include <algorithm>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int candy[1000][1000];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &candy[i][j]);
		}
	}
	static int dp[1000][1000] = {};
	dp[0][0] = candy[0][0];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(i == 0 && j == 0){
				continue;
			}else if(i == 0){
				dp[0][j] = dp[0][j-1] + candy[0][j];
			}else if(j == 0){
				dp[i][0] = dp[i-1][0] + candy[i][0];
			}else{
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + candy[i][j];
			}
		}
	}
	printf("%d", dp[n-1][m-1]);
	return 0;
}
