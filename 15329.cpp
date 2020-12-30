#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, k;
	cin >> l >> k;
	long long dp[101][2] = {};
	dp[0][0] = 1;
	dp[1][1] = 1;
	for(int len = 2; len <= l; ++len){
		dp[len][0] = dp[len - 1][1];
		dp[len][1] = dp[len - 1][0];
		if(len >= k){
			dp[len][1] += dp[len - k][0];
		}
	}
	long long ans = 0;
	for(int len = 1; len <= l; ++len){
		ans += dp[len][1];
	}
	cout << ans;
	return 0;
}
