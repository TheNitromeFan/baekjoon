#include <iostream>
#define MAX 1000001
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	long long dp[MAX][3] = {};
	for(int i = 1; i <= n; ++i){
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 1][2];
		dp[i][3] = dp[i - 1][3];
		if(a[i] == 1){
			dp[i][1] += 1;
		}else if(a[i] == 2){
			dp[i][2] += dp[i - 1][1] + dp[i - 1][2];
		}else if(a[i] == 3){
			dp[i][3] += dp[i - 1][2];
		}
		dp[i][1] %= MOD;
		dp[i][2] %= MOD;
		dp[i][3] %= MOD;
	}
	cout << dp[n][3] << '\n';
	return 0;
}
