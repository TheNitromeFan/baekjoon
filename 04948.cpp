#include <cstdio>
#include <cstdlib>

#define MAX (2*123456)


int *primes(long n){
	
	int *sieve = (int *)malloc((n+1) * sizeof(int));
	*sieve = 0;
	*(sieve+1) = 0;
	for(long i = 2; i < n+1; i++) *(sieve+i) = 1;
	for(long x = 4; x <= n; x += 2) *(sieve+x) = 0;
	for(long p = 3; p*p <= n; p += 2)
		for(long x = 2*p; x <= n; x += p) *(sieve+x) = 0;
	return sieve;
}

int main(void){
	
	int *sieve = primes(MAX);
	while(1){
		long m;
		scanf("%ld", &m);
		if(!m) break;
		long n = 2*m;
		long count = 0;
		if(m == 1){
			count++;
			m = 3;
		}
		if(m % 2) m++;
		for(long i = m+1; i <= n; i += 2)
			count += *(sieve+i);
		printf("%ld\n", count);
	}
	free(sieve);
	return 0;
}
