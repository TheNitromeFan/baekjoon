#include <cstdio>

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		long long a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a / gcd(a, b) * b);
	}
	return 0;
}
