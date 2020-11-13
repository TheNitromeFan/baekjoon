#include <cstdio>

int main(){
	int n;
	long long m;
	scanf("%d %lld", &n, &m);
	long long prod = 1;
	for(int i = 0; i < n; ++i){
		long long a;
		scanf("%lld", &a);
		prod = prod * (a % m) % m;
	}
	printf("%lld", prod);
	return 0;
}
