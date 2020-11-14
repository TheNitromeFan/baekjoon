#include <cstdio>

int divisors(int n){
	int ret = 1;
	for(int p = 2; p * p <= n; ++p){
		int mult = 1;
		while(n % p == 0){
			n /= p;
			++mult;
		}
		ret *= mult;
	}
	if(n > 1){
		ret *= 2;
	}
	return ret;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(divisors((i - 1) * n + j) <= k){
				printf("*");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
