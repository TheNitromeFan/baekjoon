#include <cstdio>
#define MAX 1000000000

int main(){
	long long fibs[100] = {};
	fibs[1] = 1;
	for(int i = 2; i < 100; ++i){
		fibs[i] = fibs[i-1] + fibs[i-2];
		if(fibs[i] > MAX){
			break;
		}
	}
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		long long n;
		scanf("%lld", &n);
		int index = 0;
		while(fibs[index] <= n){
			++index;
		}
		long long ans[100] = {};
		int i = 0, j = index - 1;
		while(n > 0 && j > 0){
			if(fibs[j] <= n){
				n -= fibs[j];
				ans[i] = fibs[j];
				++i;
				--j;
			}
			--j;
		}
		for(--i; i >= 0; --i){
			printf("%lld ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
