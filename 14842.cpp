#include <cstdio>

int main(){
	long long w, h, n;
	scanf("%lld %lld %lld", &w, &h, &n);
	printf("%.9lf", n % 2 == 1 ? h * (n - 1) * (n - 1) / 2.0 / n : h * (n - 2) / 2.0);
	return 0;
}
