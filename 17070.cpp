#include <iostream>
#define MAX 34

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	long long dp[MAX][MAX][3] = {}; // 0: right, 1: down, 2: down-right
	dp[1][2][0] = 1;
	for(int j = 3; j <= n; ++j){
		if(a[1][j] == 1){
			continue;
		}
		dp[1][j][0] = dp[1][j - 1][0];
	}
	for(int i = 2; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(a[i][j] == 1){
				continue;
			}
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
			if(a[i - 1][j] == 0 && a[i][j - 1] == 0){
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}
	printf("%lld", dp[n][n][0] + dp[n][n][1] + dp[n][n][2]);
	return 0;
}
