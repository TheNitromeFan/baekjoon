#include <cstdio>
#define MOD 1000000007

int main(){
	int t;
	scanf("%d", &t);
	for(int x = 1; x <= t; ++x){
		int c, v, l;
		scanf("%d %d %d", &c, &v, &l);
		long long words[501] = {};
		words[0] = 1;
		words[1] = v;
		for(int i = 2; i <= l; ++i){
			words[i] = v * words[i - 1] + (c * v) * words[i - 2];
			words[i] %= MOD;
		}
		printf("Case #%d: %lld\n", x, words[l]);
	}
	return 0;
}
