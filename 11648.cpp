#include <cstdio>

long long product_of_digits(long long n){
	long long ret = 1;
	while(n > 0){
		ret *= n % 10;
		n /= 10;
	}
	return ret;
}

int main(){
	long long n;
	scanf("%lld", &n);
	int ans = 0;
	while(n >= 10){
		++ans;
		n = product_of_digits(n);
	}
	printf("%d", ans);
	return 0;
}
