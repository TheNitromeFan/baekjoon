#include <cstdio>
#include <cstring>
#define MAX 2000

int points(int cards[][MAX], int dp[][MAX], int n, int left, int right){
	if(left == n || right == n){
		return 0;
	}
	if(dp[left][right] != -1){
		return dp[left][right];
	}
	dp[left][right] = 0;
	if(cards[0][left] > cards[1][right]){
		dp[left][right] = cards[1][right] + points(cards, dp, n, left, right + 1);
	}
	int cmp;
	cmp = points(cards, dp, n, left + 1, right);
	if(cmp > dp[left][right]){
		dp[left][right] = cmp;
	}
	cmp = points(cards, dp, n, left + 1, right + 1);
	if(cmp > dp[left][right]){
		dp[left][right] = cmp;
	}
	return dp[left][right];
}

int main(){
	int n;
	scanf("%d", &n);
	int cards[2][MAX];
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &cards[i][j]);
		}
	}
	static int dp[MAX][MAX];
	memset(dp, -1, sizeof(dp));
	printf("%d", points(cards, dp, n, 0, 0));
	return 0;
}
