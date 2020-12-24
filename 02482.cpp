#include <iostream>
#define MAX 1001
#define MOD 1000000003

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int dp[MAX][MAX];
	for(int i = 0; i <= n; ++i){
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for(int i = 2; i <= n; ++i){
		for(int j = 2; j <= k; ++j){
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD;
	return 0;
}
