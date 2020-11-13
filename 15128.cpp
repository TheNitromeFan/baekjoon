#include <cstdio>

int main(){
	long long p1, q1, p2, q2;
	scanf("%lld %lld %lld %lld", &p1, &q1, &p2, &q2);
	printf("%d", ((p1 * p2) % (2 * q1 * q2) == 0));
	return 0;
}
