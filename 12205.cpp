#include <iostream>
#include <string>

using namespace std;

string paren(long long dp[][101], int n, int k){
	if(dp[n][n] < k){
		return "Doesn't Exist!";
	}
	string ret = "";
	int a = n, b = n;
	while(a > 0 && b > 0){
		if(dp[a - 1][b] >= k){
			ret += '(';
			--a;
		}else{
			k -= dp[a - 1][b];
			ret += ')';
			--b;
		}
	}
	while(b > 0){
		ret += ')';
		--b;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		long long dp[101][101] = {};
		int n, k;
		cin >> n >> k;
		for(int j = 0; j <= n; ++j){
			dp[0][j] = 1;
			// cout << dp[0][j] << ' ';
		}
		// cout << '\n';
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j <= n; ++j){
				dp[i][j] = dp[i - 1][j] + (i < j ? dp[i][j - 1] : 0);
				// cout << dp[i][j] << ' ';
			}
			// cout << '\n';
		}
		cout << "Case #" << a0 << ": " << paren(dp, n, k) << "\n";
	}
	return 0;
}
