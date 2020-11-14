#include <cstdio>

int main(){
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i){
		long long li, ri;
		scanf("%lld %lld", &li, &ri);
		long long quotient = (ri - li) / 9;
		long long ans = quotient * 45;
		for(long long j = li + 9 * quotient; j <= ri; ++j){
			ans += (j - 1) % 9 + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
