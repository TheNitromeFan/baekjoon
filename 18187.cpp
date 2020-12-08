#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int dp[101] = {};
	dp[1] = 2;
	dp[2] = 4;
	int add = 3;
	for(int i = 3; i <= n; ++i){
		dp[i] = dp[i - 1] + add;
		if(i % 3 != 0){
			++add;
		}
	}
	cout << dp[n];
	return 0;
}
