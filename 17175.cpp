#include <cstdio>
#define MOD 1000000007

int main(){
	int n;
	scanf("%d", &n);
	int a[51];
	a[0] = 1;
	a[1] = 1;
	for(int i = 2; i <= n; ++i){
		a[i] = (a[i-2] + a[i-1] + 1) % MOD;
	}
	printf("%d", a[n]);
	return 0;
}
