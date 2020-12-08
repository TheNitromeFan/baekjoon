#include <iostream>
#include <algorithm>
#define MAX (100000 + 1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	static int meeting[MAX][3];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j){
			cin >> meeting[i][j];
		}
	}
	static long long dp[MAX][3] = {};
	dp[0][1] = meeting[0][2];
	for(int i = 1; i < n; ++i){
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + meeting[i][2];
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]);
	return 0;
}
