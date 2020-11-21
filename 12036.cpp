#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int x = 1; x <= t; ++x){
		int d, k, n;
		scanf("%d %d %d", &d, &k, &n);
		int i;
		if(k % 2 == 1){
			i = k + n;
		}else{
			i = k - n;
		}
		int y = (i + 1 + n) % 2 == 0 ? i + 1 + n : i + 1 - n;
		int z = (i - 1 + n) % 2 == 0 ? i - 1 + n : i - 1 - n;
		printf("Case #%d: %lld %lld\n", x, (y + 2LL * n * d - 1) % d + 1, (z + 2LL * n * d - 1) % d + 1);
	}
	return 0;
}
