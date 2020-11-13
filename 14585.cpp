#include <cstdio>
#include <algorithm>
#define MAX (300 + 1)

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static bool candy[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		candy[x][y] = true;
	}
	static long long dp[MAX][MAX] = {};
	for(int i = 0; i <= MAX; ++i){
		for(int j = 0; j <= MAX; ++j){
			if(i == 0 && j == 0){
				continue;
			}else if(i == 0){
				dp[0][j] = dp[0][j - 1];
			}else if(j == 0){
				dp[i][0] = dp[i - 1][0];
			}else{
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
			}
			if(candy[i][j]){
				dp[i][j] += std::max(m - i - j, 0);
			}
		}
	}
	printf("%lld", dp[MAX][MAX]);
	return 0;
}
