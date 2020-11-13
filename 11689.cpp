#include <cstdio>


int main(){
	long long n;
	scanf("%lld", &n);
	long long result = n;
	if(n % 2 == 0){
		while(n % 2 == 0){
			n /= 2;
		}
		result -= result / 2;
	}
	for(long long p = 3; p * p <= n; ++p){
		if(n % p == 0){
			while(n % p == 0){
				n /= p;
			}
			result -= result / p;
		}
	}
	if(n > 1){
		result -= result / n;
	}
	printf("%lld", result);
	return 0;
}
