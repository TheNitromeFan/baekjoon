#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long dp[19][201] = {};
	dp[1][0] = 1;
	for(int i = 2; i <= 18; ++i){
		for(int j = 0; j <= (i - 1) * i / 2; ++j){
			for(int k = j - i + 1; k <= j; ++k){
				if(k >= 0){
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}
	while(true){
		int n, k;
		cin >> n >> k;
		if(n == 0 && k == 0){
			break;
		}
		cout << dp[n][k] << '\n';
	}
	return 0;
}
