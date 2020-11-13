#include <cstdio>

int zeroes(int n, int b){
	int ret = 0;
	while(n % b == 0){
		++ret;
		n /= b;
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int ans = 0;
		for(int b = 2; b <= n; ++b){
			ans += zeroes(n, b);
		}
		printf("%d\n", ans);
	}
	return 0;
}
