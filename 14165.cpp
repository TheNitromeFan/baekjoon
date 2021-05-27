#include <iostream>
#include <algorithm>
#define MAX 1001
#define MOD 1000000009

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int a[MAX], b[MAX];
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int j = 0; j < m; ++j){
		cin >> b[j];
	}
	sort(a, a + n);
	sort(b, b + m);
	long long dp[10][MAX][MAX] = {}, psum[10][MAX][MAX] = {};
	for(int k1 = 0; k1 < k; ++k1){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(a[i] > b[j]){
					if(k1 > 0){
						dp[k1][i][j] = psum[k1 - 1][i][j];
					}else{
						dp[k1][i][j] = 1;
					}
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				psum[k1][i + 1][j + 1] = psum[k1][i + 1][j] + psum[k1][i][j + 1] + MOD - psum[k1][i][j] + dp[k1][i][j];
				psum[k1][i + 1][j + 1] %= MOD;
			}
		}
	}
	cout << psum[k - 1][n][m];
	return 0;
}
