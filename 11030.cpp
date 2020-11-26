#include <cstdio>

long long pow(long long base, long long exp){
	if(exp == 1){
		return base % 100000000;
	}else if(exp % 2 == 0){
		long long x = pow(base, exp / 2);
		return x * x % 100000000;
	}else{
		long long x = pow(base, exp / 2);
		return x * x % 100000000 * base % 100000000;
	}
}

long long powmod(long long base, long long exp, long long mod){
	if(exp == 1){
		return base % mod;
	}else if(exp % 2 == 0){
		long long x = pow(base, exp / 2);
		return x * x % mod;
	}else{
		long long x = pow(base, exp / 2);
		return x * x % mod * base % mod;
	}
}

int main(){
	long long a;
	int b;
	scanf("%lld %d", &a, &b);
	long long a1b = a, a2b = a;
	if(a1b % 2 == 0){
		if(b >= 4){
			a1b = 0;
		}else if(b == 3){
			a1b = powmod()
		}else if(b == 2){
			a1b = powmod(a1b, a1b, 100000000);
		}
	}else{
		for(int i = 1; i < b; ++i){
			a1b = pow(a, a1b % 64);
		}
	}
	printf("%lld", ab % 100000000);
	return 0;
}
