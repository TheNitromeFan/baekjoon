#include <cstdio>

int main(){
	long long n, p;
	scanf("%lld %lld", &n, &p);
	long long fact = 1;
	for(long long i = 2; i <= n; ++i){
		fact *= i;
		fact %= p;
	}
	printf("%lld", fact);
	return 0;
}
