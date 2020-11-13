#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int a[100001][2] = {}, dp[100001][2] = {};
		int n;
		scanf("%d", &n);
		for(int i = 0; i < 2; ++i){
			for(int j = 1; j <= n; ++j){
				scanf("%d", &a[j][i]);
			}
		}
		dp[1][0] = a[1][0];
		dp[1][1] = a[1][1];
		for(int j = 2; j <= n; ++j){
			dp[j][0] = max(dp[j-2][1], dp[j-1][1]) + a[j][0];
			dp[j][1] = max(dp[j-2][0], dp[j-1][0]) + a[j][1];
		}
		printf("%d\n", max(dp[n][0], dp[n][1]));
	}
	return 0;
}
