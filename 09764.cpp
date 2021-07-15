#include <iostream>
#define MOD 100999

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int dp[2001][2001] = {};
	for(int j = 0; j <= 2000; ++j){
		dp[0][j] = 1;
	}
	for(int i = 1; i <= 2000; ++i){
		for(int j = 1; j <= 2000; ++j){
			if(i < j){
				dp[i][j] = dp[i][j - 1];
			}else{
				dp[i][j] = (dp[i][j - 1] + dp[i - j][j - 1]) % MOD;
			}
		}
	}
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		cout << dp[n][n] << '\n';
	}
	return 0;
}
