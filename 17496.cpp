#include <cstdio>

int main(){
	int n, t, c;
	long long p;
	scanf("%d %d %d %lld", &n, &t, &c, &p);
	printf("%lld", p * c * ((n - 1) / t));
	return 0;
}
