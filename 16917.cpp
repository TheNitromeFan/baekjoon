#include <cstdio>
#include <algorithm>

using std::min;

int main(){
	long long a, b, c, x, y;
	scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &x, &y);
	long long ans = min(a + b, 2 * c) * min(x, y);
	if(x > y){
		ans += min(a, 2 * c) * (x - y);
	}else{
		ans += min(b, 2 * c) * (y - x);
	}
	printf("%lld", ans);
	return 0;
}
