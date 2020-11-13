#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", (long long)(a / b) * (a / b));
	}
	return 0;
}
