#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
		if(n % i == 0){
			ans += i;
		}
	}
	printf("%lld", ans);
	return 0;
}
