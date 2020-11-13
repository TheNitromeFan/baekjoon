#include <cstdio>
#include <climits>

int main(){
	int n;
	scanf("%d", &n);
	int dim[501][2] = {0};
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &dim[i][0], &dim[i][1]);
	}
	int dp[501][501] = {0}; // dp[i][j]: # of multiplication from i-th to j-th
	for(int len = 1; len < n; ++len){
		for(int start = 1; start + len <= n; ++start){
			int end = start + len;
			int mn = INT_MAX;
			for(int mid = start; mid < end; ++mid){
				int tmp = dp[start][mid] + dp[mid+1][end] + dim[start][0] * dim[mid][1] * dim[end][1];
				if(tmp < mn){
					mn = tmp;
				}
			}
			dp[start][end] = mn;
		}
	}
	printf("%d", dp[1][n]);
	return 0;
}
