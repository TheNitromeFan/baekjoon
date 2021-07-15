#include <iostream>
#define MAXM 21
#define MAXN 201

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int days[MAXM], page[MAXM];
	for(int i = 1; i <= m; ++i){
		cin >> days[i] >> page[i];
	}
	int dp[MAXM][MAXN] = {};
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j <= n; ++j){
			dp[i][j] = dp[i - 1][j];
			if(j >= days[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - days[i]] + page[i]);
			}
		}
	}
	cout << dp[m][n] << '\n';
	return 0;
}
