#include <cstdio>
#include <algorithm>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int map[300][300], dp[300][300] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &map[i][j]);
			if(i == 0 && j == 0){
				dp[0][0] = map[0][0];
			}else if(i == 0){
				dp[0][j] = dp[0][j-1] + map[0][j];
			}else if(j == 0){
				dp[i][0] = dp[i-1][0] + map[i][0];
			}else{
				dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]) + map[i][j];
			}
		}
	}
	printf("%d", dp[n-1][m-1]);
	return 0;
}
