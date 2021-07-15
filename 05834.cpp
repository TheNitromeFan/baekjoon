#include <iostream>
#include <algorithm>
#define MAXN 1005
#define MAX 2000000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cows[MAXN] = {};
	for(int i = 1; i <= n; ++i){
		cin >> cows[i];
	}
	++n;
	sort(cows + 1, cows + n + 1);
	int best[MAXN][MAXN][2];
	for(int i = 0; i < MAXN; ++i){
		for(int j = 0; j < MAXN; ++j){
			for(int k = 0; k < 2; ++k){
				best[i][j][k] = MAX;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		if(cows[i] == 0){
			best[i][1][0] = 0;
		}
	}
	for(int len = 1; len <= n; ++len){
		for(int i = 1; i + len <= n + 1; ++i){
			best[i - 1][len + 1][0]
			= min(best[i - 1][len + 1][0], best[i][len][0] + (n - len) * (cows[i] - cows[i - 1]));
			best[i - 1][len + 1][0]
			= min(best[i - 1][len + 1][0], best[i][len][1] + (n - len) * (cows[i + len - 1] - cows[i - 1]));
			best[i][len + 1][1]
			= min(best[i][len + 1][1], best[i][len][0] + (n - len) * (cows[i + len] - cows[i]));
			best[i][len + 1][1]
			= min(best[i][len + 1][1], best[i][len][1] + (n - len) * (cows[i + len] - cows[i + len - 1]));
		}
	}
	cout << min(best[1][n][0], best[1][n][1]);
	return 0;
}
