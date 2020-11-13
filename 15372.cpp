#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", n * n);
	}
	return 0;
}
