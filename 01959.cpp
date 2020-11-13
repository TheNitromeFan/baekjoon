#include <cstdio>

int main(){
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long times, x, y;
	if(n > m){
		times = 2 * m - 1;
		if(m % 2 == 1){
			x = n - (m - 1) / 2;
			y = (m + 1) / 2;
		}else{
			x = m / 2 + 1;
			y = m / 2;
		}
	}else{
		times = 2 * n - 2;
		if(n % 2 == 1){
			x = (n + 1) / 2;
			y = m - (n - 1) / 2;
		}else{
			x = n / 2 + 1;
			y = n / 2;
		}
	}
	printf("%lld\n%lld %lld", times, x, y);
	return 0;
}
