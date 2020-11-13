#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	long long x = 0;
	for(int i = 0; i < n + m; ++i){
		long long t;
		scanf("%lld", &t);
		x += t;
	}
	printf("%lld", x);
	return 0;
}
