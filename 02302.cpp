#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	bool vip[41] = {};
	int m;
	scanf("%d", &m);
	for(int a0 = 0; a0 < m; ++a0){
		int x;
		scanf("%d", &x);
		vip[x] = true;
	}
	int dp[41] = {}; // dp[i]: up to ith person
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; ++i){
		if(vip[i] || vip[i-1]){
			dp[i] = dp[i-1];
		}else{
			dp[i] = dp[i-1] + dp[i-2];
		}
		
	}
	printf("%d", dp[n]);
	return 0;
}
