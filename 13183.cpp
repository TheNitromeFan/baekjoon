#include <cstdio>
#define MOD 1000000007

int main(){
	long long h, w;
	scanf("%lld %lld", &h, &w);
	printf("%lld", ((h + 2) % MOD) * ((w + 2) % MOD) % MOD);
	return 0;
}
