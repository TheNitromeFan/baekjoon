#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, l0, l1, s0, s1;
		cin >> n >> l0 >> l1 >> s0 >> s1;
		int pass[2][MAX], dribble[2][MAX];
		for(int j = 0; j < n - 1; ++j){
			cin >> pass[0][j];
		}
		for(int j = 0; j < n - 1; ++j){
			cin >> dribble[0][j];
		}
		for(int j = 0; j < n - 1; ++j){
			cin >> pass[1][j];
		}
		for(int j = 0; j < n - 1; ++j){
			cin >> dribble[1][j];
		}
		int dp[2][MAX] = {};
		dp[0][0] = l0;
		dp[1][0] = l1;
		for(int j = 0; j < n - 1; ++j){
			dp[0][j + 1] = min(dp[0][j] + dribble[0][j], dp[1][j] + pass[1][j]);
			dp[1][j + 1] = min(dp[1][j] + dribble[1][j], dp[0][j] + pass[0][j]);
			// cout << dp[0][j] << ' ' << dp[1][j] << '\n';
		}
		cout << min(dp[0][n - 1] + s0, dp[1][n - 1] + s1) << '\n';
	}
	return 0;
}
