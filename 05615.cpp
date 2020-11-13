#include <cstdio>

long long a[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

long long multiply(long long x, long long y, long long mod){
	return (long long)((__int128)x * y % mod);
}

long long power(long long base, long long exponent, long long mod){
	base %= mod;
	long long result = 1;
	while(exponent > 0){
		if(exponent % 2 == 1){
			result = multiply(result, base, mod);
		}
		base = multiply(base, base, mod);
		exponent /= 2;
	}
	return result;
}

bool miller_rabin(long long n, long long b){ // true for probable prime, false for composite
	if(n % b == 0){
		return false;
	}
	long long d = n-1;
	while(d % 2 == 0){
		if(power(b, d, n) == n-1){
			return true;
		}
		d /= 2;
	}
	long long tmp = power(b, d, n);
	return tmp == n-1 || tmp == 1;
}

bool is_prime(long long n){
	for(int i = 0; i < 12; ++i){
		if(n == a[i]){
			return true;
		}else if(n > 40 && !miller_rabin(n, a[i])){
			return false;
		}
	}
	return n > 40;
}

int main(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		long long z;
		scanf("%lld", &z);
		if(is_prime(2*z+1)){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
