#include <cstdio>


long year(long m, long n, long x, long y){
	
	for(long i = 0; i < n; i++){
		if((x-1) % n == y-1) return x;
		x += m;
	}
	return -1;
}

int main(void){
	
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		long m, n, x, y;
		scanf("%ld %ld %ld %ld", &m, &n, &x, &y);
		printf("%ld\n", year(m, n, x, y));
	}
	return 0;
}
