#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += i * (i + 1) / 2;
	}
	for(int i = 1; i <= n; ++i){
		if(n % 2 != i % 2){
			ans += (i * (i + 1)) / 2;
		}
	}
	printf("%lld", ans);
	return 0;
}
