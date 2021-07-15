#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int line[101][101] = {};
	for(int i = 0; i < n; ++i){
		int s, e;
		cin >> s >> e;
		line[s][e] = 1;
		line[e][s] = 1;
	}
	int dp[101][101] = {};
	for(int i = 1; i <= 100; ++i){
		for(int j = i - 1; j >= 1; --j){
			for(int k = j; k < i; ++k){
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + line[j][i]);
			}
		}
	}
	cout << dp[1][100] << '\n';
	return 0;
}
