#include <iostream>
#define MAX 1000001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int dp[MAX] = {};
	dp[4] = 1;
	for(int i = 5; i <= n; ++i){
		dp[i] = dp[(i + 1) / 2] + 2;
	}
	cout << dp[n];
	return 0;
}
