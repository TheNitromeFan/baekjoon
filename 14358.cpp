#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAXN 201

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, k;
		cin >> n >> k;
		long double p[MAXN];
		for(int i = 0; i < n; ++i){
			cin >> p[i];
		}
		sort(p, p + n);
		long double com[MAXN];
		long double best = 0;
		for(int k0 = 0; k0 <= k; ++k0){
			for(int i = 0; i < k0; ++i){
				com[i] = p[i];
			}
			for(int i = k0; i < k; ++i){
				com[i] = p[n - 1 + k0 - i];
			}
			long double dp[MAXN][MAXN / 2 + 1] = {};
			dp[0][0] = 1;
			for(int i = 0; i < k; ++i){
				for(int j = 0; j <= k / 2; ++j){
					dp[i + 1][j + 1] += dp[i][j] * com[i];
					dp[i + 1][j] += dp[i][j] * (1 - com[i]);
				}
			}
			best = max(best, dp[k][k / 2]);
		}
		cout << fixed << setprecision(9) << "Case #" << a0 << ": " << best << "\n";
	}
	return 0;
}
