#include <cstdio>
#include <cstdlib>


int *primes(long n){
	
	int *sieve = (int *)malloc((n+1) * sizeof(int));
	for(long i = 0; i <= n; i++) *(sieve+i) = 1;
	sieve[0] = 0;
	sieve[1] = 0;
	for(long x = 4; x <= n; x += 2) *(sieve+x) = 0;
	for(long p = 3; p*p <= n; p += 2){
		for(long x = 2*p; x <= n; x += p) *(sieve+x) = 0;
	}
	return sieve;
}

int main(void){
	
	long m, n;
	scanf("%ld %ld", &m, &n);
	int *sieve;
	sieve = primes(n);
	if(m <= 2 && n >= 2){
		printf("2\n");
		m = 3;
	}
	if(m % 2 == 0) m++;
	for(long i = m; i <= n; i += 2){
		if(*(sieve+i)) printf("%ld\n", i);
	}
	free(sieve);
	return 0;
}
