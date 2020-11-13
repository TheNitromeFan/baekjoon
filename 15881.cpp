#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	static char ppap[1000001];
	scanf("%s", ppap);
	static int dp[1000001] = {};
	if(ppap[0] == 'p' && ppap[1] == 'P' && ppap[2] == 'A' && ppap[3] == 'p'){
		dp[3] = 1;
	}
	for(int i = 4; i < n; ++i){
		dp[i] = dp[i-1];
		if(ppap[i-3] == 'p' && ppap[i-2] == 'P' && ppap[i-1] == 'A' && ppap[i] == 'p'
		&& dp[i] < dp[i-4] + 1){
			dp[i] = dp[i-4] + 1;
		}
	}
	printf("%d", dp[n-1]);
	return 0;
}
