#include <cstdio>
#include <cmath>

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

long long longlongsqrt(long long n){
	if(n <= 49){
		return (long long)sqrt(n);
	}
	long long x = (long long)sqrt(n) - 5;
	while(true){
		if(x * x <= n && (x + 1) * (x + 1) > n){
			return x;
		}
		++x;
	}
	return -1;
}

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long d = b - a;
	long long n = longlongsqrt(b) - longlongsqrt(a);
	if(n == 0){
		printf("0");
		return 0;
	}
	long long g = gcd(n, d);
	printf("%lld/%lld", n / g, d / g);
	return 0;
}
