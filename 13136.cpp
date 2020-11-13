#include <cstdio>

int main(){
	long long r, c, n;
	scanf("%lld %lld %lld", &r, &c, &n);
	printf("%lld", (r % n == 0 ? r / n : r / n + 1) * (c % n == 0 ? c / n : c / n + 1));
	return 0;
}
