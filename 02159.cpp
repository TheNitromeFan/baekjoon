#include <iostream>
#include <climits>

using namespace std;

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

long long dp[100001][5];

int main(){
	int n, px, py, x, y;
	long long min, tmp;
	
	cin >> n >> px >> py;
	cin >> x >> y;
	for(int j = 0; j < 5; ++j){
		min = LLONG_MAX;
		tmp = abs((x + dx[j]) - px) + abs((y + dy[j]) - py);
		if(tmp < min){
			min = tmp;
		}
		dp[1][j] = min;
	}
	
	px = x;
	py = y;
	
	for(int i = 2; i <= n; ++i){
		cin >> x >> y;
		for(int j = 0; j < 5; ++j){
			min = LLONG_MAX;
			for(int k = 0; k < 5; ++k){
				tmp = dp[i-1][k] + abs((x + dx[j]) - (px + dx[k])) + abs((y + dy[j]) - (py + dy[k]));
				if(tmp < min){
					min = tmp;
				}
			}
			dp[i][j] = min;
		}
		px = x;
		py = y;
	}
	long long ans = dp[n][0];
	for(int j = 1; j < 5; ++j){
		if(dp[n][j] < ans){
			ans = dp[n][j];
		}
	}
	cout << ans << endl;
	return 0;
}
