#include <cstdio>
#include <cstring>

long long dp[1300][60];

long long sumi(int sum, int i){
	if(sum < 0 || i < 0){
		return 0;
	}else if(sum == 0 && i == 0){
		return 1;
	}
	if(dp[sum][i] != -1){
		return dp[sum][i];
	}
	dp[sum][i] = sumi(sum, i - 1) + sumi(sum - i, i - 1);
	return dp[sum][i];
}

long long part(int n){
	int sum = n * (n + 1) / 2;
	if(sum % 2 == 1){
		return 0;
	}
	return sumi(sum / 2, n) / 2;
}

int main(){
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%lld", part(n));
	return 0;
}
