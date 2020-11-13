#include <iostream>
#include <utility>

using namespace std;

int calc(int a, int b, char op){
	int ret = a;
	switch(op){
		case '+':
			ret += b;
			break;
		case '-':
			ret -= b;
			break;
		case '*':
			ret *= b;
			break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	char c[5][6];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> c[i][j];
		}
	}
	pair<int, int> dp[3][3];
	dp[0][0] = make_pair(c[0][0] - '0', c[0][0] - '0');
	for(int i = 0; i <= n / 2; ++i){
		for(int j = 0; j <= n / 2; ++j){
			if(i == 0 && j == 0){
				continue;
			}
			dp[i][j] = make_pair(-1000000, 1000000);
			int cmp;
			if(i > 0){
				cmp = calc(dp[i - 1][j].first, c[2 * i][2 * j] - '0', c[2 * i - 1][2 * j]);
				// cout << i << ' ' << j << ' ' << cmp << '\n';
				if(cmp > dp[i][j].first){
					dp[i][j].first = cmp;
				}
				cmp = calc(dp[i - 1][j].second, c[2 * i][2 * j] - '0', c[2 * i - 1][2 * j]);
				// cout << i << ' ' << j << ' ' << cmp << '\n';
				if(cmp < dp[i][j].second){
					dp[i][j].second = cmp;
				}
			}
			if(j > 0){
				cmp = calc(dp[i][j - 1].first, c[2 * i][2 * j] - '0', c[2 * i][2 * j - 1]);
				// cout << i << ' ' << j << ' ' << cmp << '\n';
				if(cmp > dp[i][j].first){
					dp[i][j].first = cmp;
				}
				cmp = calc(dp[i][j - 1].second, c[2 * i][2 * j] - '0', c[2 * i][2 * j - 1]);
				// cout << i << ' ' << j << ' ' << cmp << '\n';
				if(cmp < dp[i][j].second){
					dp[i][j].second = cmp;
				}
			}
			// cout << '(' << dp[i][j].first << ", " << dp[i][j].second << ") ";
		}
		// cout << '\n';
	}
	auto ans = dp[n / 2][n / 2];
	cout << ans.first << ' ' << ans.second << '\n';
	return 0;
}
