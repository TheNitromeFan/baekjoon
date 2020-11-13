#include <cstdio>

int reverse(int n){
	int ret = 0;
	while(n > 0){
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", reverse(reverse(a) + reverse(b)));
	}
	return 0;
}
