#include <cstdio>

int largestPowerOf10(int n){
	int pow10 = 1;
	while(true){
		if(pow10 == 10000 || pow10 * 10 > n){
			return pow10;
		}
		pow10 *= 10;
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = 0;
	for(int i = 0; i < m; ++i){
		int b, c1, csum = 0;
		scanf("%d %d", &b, &c1);
		for(int j = 2; j <= n; ++j){
			int cj;
			scanf("%d", &cj);
			csum += cj;
		}
		if(csum < b){
			ans += largestPowerOf10(b - csum);
		}
		if(csum + c1 <= b){
			ans -= c1;
		}
	}
	printf("%d", ans);
	return 0;
}
