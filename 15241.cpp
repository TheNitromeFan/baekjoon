#include <cstdio>
#define MAX 201
#define MOD 1000000007

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int dp[MAX][MAX] = {};
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] == 'X'){
				continue;
			}
			if(i > 0){
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= MOD;
			}
			if(j > 0){
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= MOD;
			}
		}
	}
	printf("%d", dp[n - 1][m - 1]);
	return 0;
}
