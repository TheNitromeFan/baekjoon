#include <cstdio>
#define MOD 1000000007

int main(){
	int h;
	long long x;
	scanf("%d %lld", &h, &x);
	long long sum = 0;
	long long sz = 1;
	for(int i = 0; i < h; ++i){
		int ci;
		scanf("%d", &ci);
		sz *= x;
		sz %= MOD;
		sum += sz * ci;
		sum %= MOD;
	}
	printf("%lld", sum);
	return 0;
}
