#include <cstdio>

int sum_of_divisors(int n){
	int ret = 1;
	for(int p = 2; p * p <= n; ++p){
		if(n % p != 0){
			continue;
		}
		int tmp = p;
		while(n % p == 0){
			tmp *= p;
			n /= p;
		}
		ret *= (tmp - 1) / (p - 1);
	}
	if(n > 1){
		ret *= (1 + n);
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int x;
		scanf("%d", &x);
		int cmp = sum_of_divisors(x);
		if(cmp == 2 * x){
			printf("Perfect\n");
		}else if(cmp < 2 * x){
			printf("Deficient\n");
		}else{
			printf("Abundant\n");
		}
	}
	return 0;
}
