#include <iostream>
#include <iomanip>
#define MAX 51

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y, k;
	cin >> n >> x >> y >> k;
	double dp[MAX][MAX][MAX] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			dp[i][j][0] = 1;
		}
	}
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	for(int s = 1; s <= k; ++s){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				for(int idx = 0; idx < 8; ++idx){
					int ni = i + dx[idx], nj = j + dy[idx];
					if(ni >= 1 && ni <= n && nj >= 1 && nj <= n){
						dp[i][j][s] += dp[ni][nj][s - 1];
					}
				}
				dp[i][j][s] /= 8;
			}
		}
	}
	cout << setprecision(11) << dp[x][y][k];
	return 0;
}
