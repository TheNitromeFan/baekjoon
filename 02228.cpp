#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100
#define MIN -3276800

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[MAX + 1];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int dp[MAX + 1][MAX + 1] = {}; // dp[i][j]: i numbers, j intervals
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= n; ++j){
			dp[i][j] = MIN;
		}
	}
	for(int i = 1; i <= n; ++i){
		dp[i][1] = dp[i - 1][1];
		int sum = 0;
		for(int k = i; k > 0; --k){
			sum += a[k];
			if(dp[i][1] < sum){
				dp[i][1] = sum;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 2; j <= (i + 1) / 2; ++j){
			dp[i][j] = dp[i - 1][j];
			int sum = 0;
			for(int k = i; k > 2 * (j - 1); --k){
				sum += a[k];
				if(dp[i][j] < dp[k - 2][j - 1] + sum){
					dp[i][j] = dp[k - 2][j - 1] + sum;
				}
			}
		}
	}
	/*
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d", dp[n][m]);
	return 0;
}
