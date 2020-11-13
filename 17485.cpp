#include <cstdio>
#include <algorithm>
#define MAX 1000

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int a[MAX][MAX], dp[MAX][MAX][3];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	for(int j = 0; j < m; ++j){
		for(int k = 0; k < 3; ++k){
			dp[0][j][k] = a[0][j];
		}
	}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(j == 0){
				dp[i][0][1] = dp[i - 1][0][2] + a[i][0];
				dp[i][0][2] = min(dp[i - 1][1][0], dp[i - 1][1][1]) + a[i][0];
			}else if(j == m - 1){
				dp[i][m - 1][0] = min(dp[i - 1][m - 2][1], dp[i - 1][m - 2][2]) + a[i][m - 1];
				dp[i][m - 1][1] = dp[i - 1][m - 1][0] + a[i][m - 1];
			}else{
				dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + a[i][j];
				dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + a[i][j];
				dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + a[i][j];
			}
		}
	}
	int ans = 100000000;
	for(int j = 0; j < m; ++j){
		for(int k = 0; k < 3; ++k){
			if((j == 0 && k == 0) || (j == m - 1 && k == 2)){
				continue;
			}
			if(ans > dp[n - 1][j][k]){
				ans = dp[n - 1][j][k];
			}
		}
	}
	printf("%d", ans);
	return 0;
}
