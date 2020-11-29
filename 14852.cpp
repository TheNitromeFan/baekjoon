#include <cstdio>
#define MOD 1000000007

int main(){
	int n;
	scanf("%d", &n);
	static long long a[1000001] = {};
	a[0] = 1;
	a[1] = 2;
	a[2] = 7;
	for(int i = 3; i <= n; ++i){
		a[i] = (3 * a[i - 1] + a[i - 2] - a[i - 3]) % MOD;
	}
	while(a[n] < 0){
		a[n] += MOD;
	}
	printf("%lld", a[n]);
	return 0;
}
