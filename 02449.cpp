#include <cstdio>
#include <cstring>
#include <climits>

int dp[201][201];

int bulbs[201];

int solve(int start, int end){
	if(start == end){
		return 0;
	}
	if(dp[start][end] != -1){
		return dp[start][end];
	}
	dp[start][end] = INT_MAX;
	for(int middle = start; middle < end; ++middle){
		int button = (bulbs[start] == bulbs[middle+1])? 0 : 1;
		int to_compare = solve(start, middle) + solve(middle+1, end) + button;
		if(to_compare < dp[start][end]){
			dp[start][end] = to_compare;
		}
	}
	return dp[start][end];
}

int main(){
	int n, m;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &bulbs[i]);
	}
	printf("%d", solve(1, n));
	return 0;
}
