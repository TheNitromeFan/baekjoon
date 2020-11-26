#include <cstdio>
#define MOD 1000000

int main(){
	long long n;
	scanf("%lld", &n);
	long long k = n / 6 % MOD;
	int r = n % 6;
	long long ans = 0;
	switch(r){
		case 0:
			ans = 3 * k * k + 3 * k + 1;
			break;
		case 1:
			ans = 3 * k * k + 4 * k + 1;
			break;
		case 2:
			ans = 3 * k * k + 5 * k + 2;
			break;
		case 3:
			ans = 3 * k * k + 6 * k + 3;
			break;
		case 4:
			ans = 3 * k * k + 7 * k + 4;
			break;
		case 5:
			ans = 3 * k * k + 8 * k + 5;
			break;
	}
	printf("%lld", ans % MOD);
	return 0;
}
