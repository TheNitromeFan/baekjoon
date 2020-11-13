#include <cstdio>

int main(){
	int p;
	scanf("%d", &p);
	for(int a0 = 0; a0 < p; ++a0){
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", n * (n + 1) * (2 * n + 1) / 6);
	}
	return 0;
}
