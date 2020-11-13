#include <cstdio>
#define MAX (1000000 + 1)
#define MOD 1000000009

int main(){
	static char format[MAX];
	scanf("%s", format);
	static long long dp[MAX] = {};
	if(format[0] == 'd'){
		dp[0] = 10;
	}else{
		dp[0] = 26;
	}
	int i;
	for(i = 1; format[i] != '\0'; ++i){
		int multiplier;
		if(format[i] == 'd'){
			multiplier = 10;
		}else{
			multiplier = 26;
		}
		if(format[i] == format[i - 1]){
			--multiplier;
		}
		dp[i] = dp[i - 1] * multiplier;
		dp[i] %= MOD;
	}
	printf("%lld", dp[i - 1]);
	return 0;
}
