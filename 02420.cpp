#include <cstdio>
#include <cstdlib>

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", llabs(a - b));
	return 0;
}
