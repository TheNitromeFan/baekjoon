#include <cstdio>
#define MOD 1000000007

int main(){
	int n;
	long long x;
	scanf("%d %lld", &n, &x);
	long long a;
	int i;
	scanf("%lld %d", &a, &i);
	for(int j = n - 1; j >= 0; --j){
		long long aj;
		scanf("%lld %d", &aj, &i);
		a = (a * x + aj) % MOD;
	}
	printf("%lld", a);
	return 0;
}
