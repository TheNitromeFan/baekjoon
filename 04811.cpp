#include <cstdio>

long long dp[31][31];

long long ways(int w, int h){
	if(w == 0){
		return 1;
	}else if(dp[w][h]){
		return dp[w][h];
	}
	dp[w][h] = ways(w - 1, h + 1);
	if(h > 0){
		dp[w][h] += ways(w, h - 1);
	}
	return dp[w][h];
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		printf("%lld\n", ways(n, 0));
	}
	return 0;
}
