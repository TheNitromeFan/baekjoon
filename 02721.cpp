#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		long long sum = 0;
		for(int k = 1; k <= n; ++k){
			sum += k * (k + 1) * (k + 2) / 2;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
