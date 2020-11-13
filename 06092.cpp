#include <cstdio>

int main(){
	long long a[13];
	for(int k = 0; k <= 12; ++k){
		a[k] = (1LL << k) - 1;
	}
	long long b[13] = {};
	b[1] = 1;
	printf("%lld\n", b[1]);
	for(int n = 2; n <= 12; ++n){
		b[n] = 100000000000000000LL;
		for(int k = 1; k < n; ++k){
			if(b[n - k] + a[k] + b[n - k] < b[n]){
				b[n] = b[n - k] + a[k] + b[n - k];
			}
		}
		printf("%lld\n", b[n]);
	}
	return 0;
}
