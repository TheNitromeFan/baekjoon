#include <cstdio>

int sum_of_divisors(int n){
	int ans = 1;
	for(int p = 2; p * p <= n; ++p){
		int tmp = 0;
		int power;
		for(power = 1; n % power == 0; power *= p){
			tmp += power;
		}
		ans *= tmp;
		n /= (power / p);
	}
	if(n > 1){
		ans *= (1 + n);
	}
	return ans;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		printf("%d ", n);
		int cmp = sum_of_divisors(n);
		if(cmp == 2 * n){
			printf("PERFECT");
		}else if(cmp < 2 * n){
			printf("DEFICIENT");
		}else{
			printf("ABUNDANT");
		}
		printf("\n");
	}
	return 0;
}
