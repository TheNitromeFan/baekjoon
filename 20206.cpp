#include <cstdio>

int main(){
	long long a, b, c, x1, x2, y1, y2;
	scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &x1, &x2, &y1, &y2);
	printf("%s", (a * x1 + b * y1 + c) * (a * x2 + b * y2 + c) < 0
	|| (a * x1 + b * y2 + c) * (a * x2 + b * y1 + c) < 0 ? "Poor" : "Lucky");
	return 0;
}
