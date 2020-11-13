#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

int main(){
	long long x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	long long a = max(x1, x3), b = max(y2, y4), c = min(x2, x4), d = min(y1, y3);
	printf("%lld", max(c - a, 0LL) * max(d - b, 0LL));
	return 0;
}
