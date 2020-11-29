#include <cstdio>
#include <cstring>

int bribe(int dp[][110], int a[110], int i, int j){
	if(i + 1 >= j){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	dp[i][j] = 1000000000;
	for(int k = i + 1; k <= j - 1; ++k){
		int cmp = bribe(dp, a, i, k) + bribe(dp, a, k, j) + a[j] - a[i] - 2;
		if(cmp < dp[i][j]){
			dp[i][j] = cmp;
		}
	}
	return dp[i][j];
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int p, q;
		scanf("%d %d", &p, &q);
		int a[110] = {};
		for(int i = 1; i <= q; ++i){
			scanf("%d", &a[i]);
		}
		a[q + 1] = p + 1;
		int dp[110][110];
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", a0, bribe(dp, a, 0, q + 1));
	}
	return 0;
}
