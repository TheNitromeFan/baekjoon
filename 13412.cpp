#include <cstdio>

int prime_factors(int n){
	int ret = 0;
	for(int p = 2; p * p <= n; ++p){
		if(n % p != 0){
			continue;
		}
		++ret;
		while(n % p == 0){
			n /= p;
		}
	}
	if(n > 1){
		++ret;
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		if(n == 1){
			printf("1\n");
			continue;
		}
		printf("%d\n", (1 << (prime_factors(n) - 1)));
	}
	return 0;
}
