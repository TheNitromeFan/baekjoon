#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int a[1001][1001] = {};
	for(int i = 1; i <= n; ++i){
		char line[1001];
		scanf("%s", line);
		for(int j = 1; j <= m; ++j){
			a[i][j] = line[j-1] - '0';
		}
	}
	static int dp[1001][1001] = {};
	int mx = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(a[i][j]){
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
				if(dp[i][j] > mx){
					mx = dp[i][j];
				}
			}
		}
	}
	printf("%d", mx * mx);
	return 0;
}
