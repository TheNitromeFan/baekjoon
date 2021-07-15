#include <iostream>
#include <algorithm>
#define MAX 200001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long k;
	cin >> n >> k;
	long long a[MAX], b[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
	}
	long long dp[MAX][2] = {};
	for(int i = 1; i <= n; ++i){
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + k) + a[i];
		dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + k) + b[i];
	}
	cout << min(dp[n][0], dp[n][1]) << '\n';
	return 0;
}
