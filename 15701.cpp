#include <cstdio>

int factors(int n){
	int ret = 1;
	for(int p = 2; p * p <= n; ++p){
		int mult = 1;
		while(n % p == 0){
			++mult;
			n /= p;
		}
		ret *= mult;
	}
	if(n > 1){
		ret *= 2;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", factors(n));
	return 0;
}
