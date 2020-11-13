#include <cstdio>
#define MAX (10000 + 1)
#define MOD 987654321

int main(){
	int n;
	scanf("%d", &n);
	long long a[MAX] = {};
	a[0] = 1;
	for(int i = 2; i <= n; i += 2){
		for(int k = 0; k < i; k += 2){
			a[i] = (a[i] + a[k] * a[i - k - 2]) % MOD;
		}
	}
	printf("%lld", a[n]);
	return 0;
}
