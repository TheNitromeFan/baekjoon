#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	long long dp[50][2] = {};
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i = 2; i < 50; ++i){
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	for(int a0 = 1; a0 <= t; ++a0){
		int x;
		cin >> x;
		cout << "Scenario #" << a0 << ":\n" << dp[x][0] + dp[x][1] << "\n\n";
	}
	return 0;
}
