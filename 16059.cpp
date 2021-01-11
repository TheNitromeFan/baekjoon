#include <iostream>
#include <algorithm>
#define MAX 300001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> x[i];
	}
	int dp[MAX][11] = {};
	for(int i = m + 1; i <= n; ++i){
		dp[i][1] = dp[i - 1][m] + x[i];
		for(int j = 2; j < m; ++j){
			dp[i][j] = dp[i - 1][j - 1];
		}
		dp[i][m] = max(dp[i][m], max(dp[i - 1][m - 1], dp[i - 1][m]));
	}
	int ans = 0;
	for(int j = 0; j <= m; ++j){
		ans = max(ans, dp[n][j]);
	}
	cout << ans;
	return 0;
}
