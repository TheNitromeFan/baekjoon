#include <cstdio>
#define MAX (10000 + 1)

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int p, q;
		scanf("%d %d", &p, &q);
		long long fib[MAX + 1];
		fib[1] = 1 % q;
		fib[2] = 1 % q;
		for(int j = 3; j <= p; ++j){
			fib[j] = (fib[j - 1] + fib[j - 2]) % q;
		}
		printf("Case #%d: %lld\n", i, fib[p]);
	}
	return 0;
}
