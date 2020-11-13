#include <cstdio>
#include <algorithm>

long long dist(long long x, long long y){
	return x * x + y * y;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("%lld\n", std::min(std::min(dist(a + b, c), dist(b + c, a)), dist(c + a, b)));
	}
	return 0;
}
