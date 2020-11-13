#include <cstdio>

int main(){
	int c;
	scanf("%d", &c);
	for(int i = 0; i < c; ++i){
		int n;
		scanf("%d", &n);
		int divisors = 0;
		for(int j = 1; j <= n; ++j){
			if(n % j == 0){
				++divisors;
			}
		}
		printf("%d %d\n", n, divisors);
	}
	return 0;
}
