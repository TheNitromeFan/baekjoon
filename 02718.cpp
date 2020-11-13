#include <cstdio>
#define MAX (1000 + 1)

int main(){
	int t;
	scanf("%d", &t);
	int dp[MAX][4] = {};
	dp[0][0] = 1;
	for(int w = 1; w < MAX; ++w){
		dp[w][0] = dp[w - 1][0] + 2 * dp[w - 1][1] + dp[w - 1][3];
		if(w > 1){
			dp[w][0] += dp[w - 2][0];
		}
		dp[w][1] = dp[w - 1][0] + dp[w - 1][1];
		dp[w][2] = dp[w - 1][3];
		dp[w][3] = dp[w - 1][0] + dp[w - 1][2];
	}
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n][0]);
	}
	return 0;
}
