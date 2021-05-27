#include <iostream>
#define MAX 50001
#define MOD 1000000009

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long dp[MAX] = {};
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for(int i = 4; i <= n; ++i){
		dp[i] = dp[i - 1] + dp[i - 3];
		dp[i] %= MOD;
	}
	cout << dp[n];
	return 0;
}
