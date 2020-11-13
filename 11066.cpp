#include <cstdio>
#include <algorithm>
#include <limits>
#define MAX 500

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int k;
		scanf("%d", &k);
		int book[MAX+1], psum[MAX+1] = {};
		int dp[MAX+1][MAX+1] = {};
		for(int i = 1; i <= k; ++i){
			scanf("%d", &book[i]);
			psum[i] = psum[i - 1] + book[i];
		}
		for(int len = 1; len <= k-1; ++len){
			for(int i = 1; i + len <= k; ++i){
				int j = i + len;
				dp[i][j] = std::numeric_limits<int>::max();
				for(int m = i; m < j; ++m){
					int cmp = dp[i][m] + dp[m+1][j] + psum[j] - psum[i-1];
					if(dp[i][j] > cmp){
						dp[i][j] = cmp;
					}
				}
			}
		}
		printf("%d\n", dp[1][k]);
	}
	return 0;
}
