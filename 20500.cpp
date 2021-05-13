#include <iostream>
#define MAX 1520
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int dp[MAX][3] = {};
	dp[1][2] = 1;
	for(int i = 2; i <= n; ++i){
		dp[i][0] = (dp[i - 1][2] + dp[i - 1][1]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
	}
	cout << dp[n][0];
	return 0;
}
