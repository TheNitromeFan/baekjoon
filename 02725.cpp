#include <cstdio>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int dp[1002] = {};
	for(int i = 0; i <= 1000; ++i){
		dp[i] = dp[i - 1];
		for(int j = 0; j < i; ++j){
			if(gcd(i, j) == 1){
				dp[i] += 2;
			}
		}
	}
	int c;
	scanf("%d", &c);
	for(int a0 = 0; a0 < c; ++a0){
		int n;
		scanf("%d", &n);
		printf("%d\n", dp[n] + 1);
	}
	return 0;
}
