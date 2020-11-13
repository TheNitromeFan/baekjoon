#include <stdio.h>
#include <map>


std::map<long long, long long> fibs;

long mod = 1000000000;
long p = mod / 10 * 15;

long long fibonacci(long long x){
	
	x %= p;
	if(x == 0) return 0;
	else if(x == 1) return 1;
	else if(x == 2) return 1;
	else if(fibs.count(x)) return fibs[x];
	else{
		long long f1, f2;
		if(x % 2){
			f1 = fibonacci(x/2);
			f2 = fibonacci(x/2 + 1);
			fibs[x] = (f1*f1 + f2*f2) % mod;
		}else{
			f1 = fibonacci(x/2 - 1);
			f2 = fibonacci(x/2);
			fibs[x] = (2*f1 + f2)*f2 % mod;
		}
		return fibs[x];
	}
}


int main(void){
	
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", (fibonacci(b+2) - fibonacci(a+1) + mod) % mod);
}
