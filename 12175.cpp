#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		long long k;
		int v;
		scanf("%lld %d", &k, &v);
		long long ans = 0;
		if(v == 0){
			ans = k + 1;
		}else if(v == 1){
			ans = k + 1 + 6 * k;
		}else if(v == 2){
			ans = k + 1 + 6 * k + 6 * 2 * (k - 1);
		}else{
			ans = k + 1 + (long long)v * (v + 1) * (3 * k - 2 * v + 2);
		}
		printf("Case #%d: %lld\n", a0, ans);
	}
	return 0;
}
