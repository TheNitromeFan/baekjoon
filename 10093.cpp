#include <cstdio>
#include <algorithm>

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	if(a == b){
		printf("0");
		return 0;
	}
	if(a > b){
		std::swap(a, b);
	}
	printf("%lld\n", b - a - 1);
	for(long long x = a + 1; x < b; ++x){
		printf("%lld ", x);
	}
	return 0;
}
