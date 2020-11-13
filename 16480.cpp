#include <cstdio>

int main(){
	int circum, in;
	scanf("%d %d", &circum, &in);
	printf("%lld", (long long)circum * (circum - 2 * in));
	return 0;
}
