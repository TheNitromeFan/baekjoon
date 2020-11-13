#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long ans = 1;
	for(int i = 1; i <= n; ++i){
		ans *= i;
		ans %= 1000000000000;
		while(ans % 10 == 0){
			ans /= 10;
		}
	}
	ans %= 10;
	printf("%lld", ans);
	return 0;
}
