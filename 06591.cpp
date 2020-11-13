#include <cstdio>


long long combination(long n, long k){
	
	if(k == 0 || n == k) return 1;
	else if(k <= n/2) return combination(n-1, k-1) * n / k;
	else return combination(n-1, k) * n / (n-k);
}

int main(void){
	
	long n, k;
	while(1){
		scanf("%ld %ld", &n, &k);
		if(n == 0 && k == 0) break;
		printf("%lld\n", combination(n, k));
	}
	return 0;
}
