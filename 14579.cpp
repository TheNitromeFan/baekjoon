#include <cstdio>
#define MOD 14579

int t(int x){
	return x * (x + 1) / 2 % MOD;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int ans = 1;
	for(int i = a; i <= b; ++i){
		ans *= t(i);
		ans %= MOD;
	}
	printf("%d", ans);
	return 0;
}
