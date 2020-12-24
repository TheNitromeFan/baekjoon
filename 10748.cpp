#include <iostream>
#define MAX 101
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c, n;
	cin >> r >> c >> n;
	int grid[MAX][MAX];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> grid[i][j];
		}
	}
	int dp[MAX][MAX] = {};
	dp[0][0] = 1;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			for(int k = 0; k < i; ++k){
				for(int l = 0; l < j; ++l){
					if(grid[i][j] != grid[k][l]){
						dp[i][j] += dp[k][l];
						dp[i][j] %= MOD;
					}
				}
			}
		}
	}
	cout << dp[r - 1][c - 1];
	return 0;
}
