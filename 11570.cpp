#include <iostream>
#include <cstdlib>
#include <algorithm>
#define MAXN 2001
#define MAXVAL 2100000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAXN];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int dp[MAXN][MAXN];
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= n; ++j){
			dp[i][j] = MAXVAL;
		}
	}
	dp[1][0] = 0;
	dp[0][1] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i == j){
				continue;
			}
			int k = max(i, j) + 1;
			if(i == 0){
				dp[k][j] = min(dp[k][j], dp[0][j]);
			}else{
				dp[k][j] = min(dp[k][j], dp[i][j] + abs(a[i] - a[k]));
			}
			if(j == 0){
				dp[i][k] = min(dp[i][k], dp[i][0]);
			}else{
				dp[i][k] = min(dp[i][k], dp[i][j] + abs(a[j] - a[k]));
			}
		}
	}
	int ans = MAXVAL;
	for(int i = 0; i <= n; ++i){
		ans = min(ans, min(dp[i][n], dp[n][i]));
	}
	cout << ans << '\n';
	return 0;
}
