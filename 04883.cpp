#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		++t;
		static int graph[100001][3];
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < 3; ++j){
				cin >> graph[i][j];
			}
		}
		static long long dp[100001][3] = {};
		dp[1][0] = graph[1][1];
		dp[1][1] = graph[1][1];
		dp[1][2] = graph[1][1] + graph[1][2];
		for(int i = 2; i <= n; ++i){
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
			dp[i][1] = min(min(dp[i - 1][1], dp[i - 1][2]),
			               min(dp[i - 1][0], dp[i][0])) + graph[i][1];
			dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]),
			               dp[i][1]) + graph[i][2];
		}
		cout << t << ". " << dp[n][1] << "\n";
	}
	return 0;
}
