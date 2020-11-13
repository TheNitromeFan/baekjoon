#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::min;

int main(){
	long long x, y, w, s;
	scanf("%lld %lld %lld %lld", &x, &y, &w, &s);
	long long a = min(x, y) * min(s, 2 * w);
	long long z = abs(x - y);
	long long b = z / 2 * std::min(2 * s, 2 * w);
	if(z % 2 == 1){
		b += w;
	}
	printf("%lld", a + b);
	return 0;
}
