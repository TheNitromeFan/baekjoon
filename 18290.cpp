#include <iostream>
#include <algorithm>
#define MINVAL -1000000000

using namespace std;

int ones(int n){
	int ret = 0;
	while(n){
		ret += n & 1;
		n >>= 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, c;
	cin >> n >> m >> c;
	int a[11][11];
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}
	int psum[11][3000] = {};
	int bitcount[3000];
	for(int i = 1; i <= n; ++i){
		for(int k = 0; k < (1 << m); ++k){
			bitcount[k] = ones(k);
			for(int j = 0; j < m; ++j){
				if(k & (1 << j)){
					psum[i][k] += a[i][j];
				}
			}
		}
	}
	int dp[11][51][3000];
	for(int i = 0; i <= 10; ++i){
		for(int j = 0; j <= 50; ++j){
			for(int k = 0; k < 3000; ++k){
				dp[i][j][k] = MINVAL;
				if(i == 0 && j == 0){
					dp[i][j][k] = 0;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int k = 0; k < (1 << m); ++k){
			bool flag = false;
			for(int j = 1; j < m; ++j){
				if((k & (1 << j)) && (k & (1 << (j - 1)))){
					flag = true;
					break;
				}
			}
			if(flag){
				continue;
			}
			for(int bk = 0; bk < (1 << m); ++bk){
				for(int j = bitcount[k]; j <= c; ++j){
					if(!(k & bk)){
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - bitcount[k]][bk] + psum[i][k]);
					}
				}
			}
		}
	}
	int ans = MINVAL;
	for(int k = 0; k < (1 << m); ++k){
		ans = max(ans, dp[n][c][k]);
	}
	cout << ans << '\n';
	return 0;
}
