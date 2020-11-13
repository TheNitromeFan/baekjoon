#include <cstdio>
#define MOD 1234567

void compute(int comb[][10], int n){
	for(int j = 0; j < 10; ++j){
		comb[1][j] = 1;
	}
	for(int i = 2; i <= n; ++i){
		comb[i][0] = comb[i-1][7];
		comb[i][1] = (comb[i-1][2] + comb[i-1][4]) % MOD;
		comb[i][2] = (comb[i-1][1] + comb[i-1][3] + comb[i-1][5]) % MOD;
		comb[i][3] = (comb[i-1][2] + comb[i-1][6]) % MOD;
		comb[i][4] = (comb[i-1][1] + comb[i-1][5] + comb[i-1][7]) % MOD;
		comb[i][5] = (comb[i-1][2] + comb[i-1][4] + comb[i-1][6] + comb[i-1][8]) % MOD;
		comb[i][6] = (comb[i-1][3] + comb[i-1][5] + comb[i-1][9]) % MOD;
		comb[i][7] = (comb[i-1][0] + comb[i-1][4] + comb[i-1][8]) % MOD;
		comb[i][8] = (comb[i-1][5] + comb[i-1][7] + comb[i-1][9]) % MOD;
		comb[i][9] = (comb[i-1][6] + comb[i-1][8]) % MOD;
	}
}

int main(){
	int comb[1001][10] = {};
	// comb[m][n]: passes of length m ending in n
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		compute(comb, n);
		int ans = 0;
		for(int j = 0; j < 10; ++j){
			ans += comb[n][j];
		}
		ans %= MOD;
		printf("%d\n", ans);
	}
	return 0;
}

