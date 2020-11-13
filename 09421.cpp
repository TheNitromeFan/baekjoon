#include <cstdio>
#define MAX 1000000

bool is_not_prime[MAX+1];

int dp[MAX+1];

void sieve(){
	is_not_prime[0] = true;
	is_not_prime[1] = true;
	for(int m = 2; m * 2 <= MAX; ++m){
		is_not_prime[m * 2] = true;
	}
	for(int p = 3; p * p <= MAX; p += 2){
		for(int m = p; m * p <= MAX; m += 2){
			is_not_prime[m * p] = true;
		}
	}
}

bool is_acyclic(int n){
	int m = n;
	while(dp[n] == 0){
		int tmp = 0;
		while(n > 0){
			int digit = n % 10;
			tmp += digit * digit;
			n /= 10;
		}
		n = tmp;
	}
	if(dp[n] == 1){
		dp[m] = 1;
		return true;
	}else{
		dp[m] = -1;
		return false;
	}
}

int main(){
	sieve();
	dp[1] = 1;
	dp[4] = -1;
	dp[16] = -1;
	dp[37] = -1;
	dp[58] = -1;
	dp[89] = -1;
	dp[145] = -1;
	dp[42] = -1;
	dp[20] = -1;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		if(!is_not_prime[i] && is_acyclic(i)){
			printf("%d\n", i);
		}
	}
	return 0;
}
