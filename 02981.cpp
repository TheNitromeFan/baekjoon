#include <cstdio>
#include <cstdlib>

#define MAX 31623


long gcd(long a, long b){
	
	if(a < b) return gcd(b, a);
	else if(b == 0) return a;
	else return gcd(b, a % b);
}

void print_divisors(long n){
	
	long *d = (long *)malloc(MAX * sizeof(long));
	long index = 0;
	for(long i = 2; i*i <= n; i++)
		if(n % i == 0){
			printf("%ld ", i);
			if(n - i*i){
				*(d+index) = n/i;
				index++;
			}
		}
	for(long i = index-1; i >= 0; i--) printf("%ld ", *(d+i));
	printf("%ld", n);
}

int main(void){
	
	int n;
	scanf("%d", &n);
	long *a = (long *)malloc(n * sizeof(long));
	long *d = (long *)malloc((n-1) * sizeof(long));
	scanf("%ld", a);
	scanf("%ld", a+1);
	*d = labs(*(a+1) - *a);
	long g = *d;
	for(int i = 2; i < n; i++){
		scanf("%ld", a+i);
		*(d+i-1) = labs(*(a+i) - *(a+i-1));
		g = gcd(g, *(d+i-1));
	}
	free(a);
	print_divisors(g);
	free(d);
	return 0;
}
