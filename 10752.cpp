#include <cstdio>
#define MAX 16

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	long long dp[MAX][MAX] = {};
	dp[0][0] = 1;
	for(int i = 1; i < r; ++i){
		for(int j = 1; j < c; ++j){
			for(int k = 0; k < i; ++k){
				for(int l = 0; l < j; ++l){
					if(map[i][j] != map[k][l]){
						dp[i][j] += dp[k][l];
					}
				}
			}
		}
	}
	printf("%lld\n", dp[r - 1][c - 1]);
	return 0;
}
