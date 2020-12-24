#include <iostream>
#include <algorithm>
#define MAX 501

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w;
	cin >> h >> w;
	int a[MAX][MAX];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> a[i][j];
		}
	}
	int dp[MAX][MAX];
	for(int j = 0; j < w; ++j){
		dp[0][j] = a[0][j];
	}
	for(int i = 1; i < h; ++i){
		for(int j = 0; j < w; ++j){
			dp[i][j] = dp[i - 1][j];
			if(j - 1 >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			}
			if(j + 1 < w){
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
			}
			dp[i][j] += a[i][j];
		}
	}
	int ans = dp[h - 1][0];
	for(int j = 1; j < w; ++j){
		ans = max(ans, dp[h - 1][j]);
	}
	cout << ans;
	return 0;
}
