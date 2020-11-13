#include <cstdio>
#include <cstdlib>


long **residents(int k, int n){
	
	long **people = (long **)malloc((k+1) * sizeof(long *));
	for(int a = 0; a <= k; a++){
		*(people+a) = (long *)malloc((n+1) * sizeof(long));
		for(int b = 1; b <= n; b++){
			if(b == 1) *(*(people+a)+1) = 1;
			else if(a == 0) *(*people+b) = b;
			else *(*(people+a)+b) = *(*(people+a-1)+b) + *(*(people+a)+b-1);
		}
	}
	return people;
}

int main(void){
	
	long t;
	scanf("%ld", &t);
	long **apartment = residents(14, 14);
	for(long i = 0; i < t; i++){
		int k, n;
		scanf("%d %d", &k, &n);
		printf("%ld\n", *(*(apartment+k)+n));
	}
	free(apartment);
	return 0;
}
