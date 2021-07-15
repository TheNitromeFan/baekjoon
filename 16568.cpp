#include <iostream>
#include <algorithm>
#define MAX 1000001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	int dp[MAX];
	dp[0] = 0;
	for(int i = 1; i <= n; ++i){
		dp[i] = dp[i - 1] + 1;
		if(i >= a + 1){
			dp[i] = min(dp[i], dp[i - a - 1] + 1);
		}
		if(i >= b + 1){
			dp[i] = min(dp[i], dp[i - b - 1] + 1);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}
