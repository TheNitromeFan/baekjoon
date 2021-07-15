#include <cstdio>
#define MOD 1000000007

int main(){
	int n;
	scanf("%d", &n);
	if(n % 2 == 1){
		printf("0");
		return 0;
	}
	long long a[1001] = {};
	a[0] = 1;
	for(int i = 2; i <= n; i += 2){
		a[i] = 3 * a[i-2] % MOD;
		for(int j = i - 4; j >= 0; j -= 2){
			a[i] += 2 * a[j];
			a[i] %= MOD;
		}
	}
	printf("%lld", a[n]);
	return 0;
}
