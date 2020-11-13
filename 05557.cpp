#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int nums[101];
	long long dp[101][21] = {}; // dp[i][j]: make j out of first i terms
	for(int i = 0; i < n; ++i){
		cin >> nums[i];
	}
	dp[0][nums[0]] = 1;
	for(int i = 1; i < n-1; ++i){
		for(int j = 0; j <= 20; ++j){
			if(j + nums[i] <= 20){
				dp[i][j + nums[i]] += dp[i-1][j];
			}
			if(j - nums[i] >= 0){
				dp[i][j - nums[i]] += dp[i-1][j];
			}
		}
	}
	cout << dp[n-2][nums[n-1]];
	return 0;
}
