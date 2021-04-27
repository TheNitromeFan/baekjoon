#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long dp[1001] = {};
	dp[1] = 1;
	dp[2] = 2;
	for(int n = 3; n <= 1000; ++n){
		dp[n] = 1;
		if(n % 2 == 1){
			for(int i = 1; i <= n; i += 2){
				dp[n] += dp[(n - i) / 2];
			}
		}else{
			for(int i = 0; i <= n; i += 2){
				dp[n] += dp[(n - i) / 2];
			}
		}
	}
	int t;
	cin >> t;
	for(int j = 0; j < t; ++j){
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
