#include <iostream>
#define MAX 5001
#define MOD 1000000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	long long dp[MAX][MAX] = {}, psum[MAX][MAX] = {};
	dp[0][0] = 1;
	for(int j = 0; j <= n; ++j){
		psum[0][j] = 1;
	}
	for(int i = 1; i <= k; ++i){
		for(int j = 0; j <= n; ++j){
			dp[i][j] = psum[i - 1][j];
			if(j > 0){
				psum[i][j] = (psum[i][j - 1] + dp[i][j]) % MOD;
			}else{
				psum[i][0] = 1;
			}
		}
	}
	cout << dp[k][n];
	return 0;
}
