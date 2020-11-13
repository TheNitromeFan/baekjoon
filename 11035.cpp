#include <cstdio>

int solve(int n, int k){
	bool sieve[1001] = {};
	int cnt = 0;
	for(int p = 2; p <= n; ++p){
		if(sieve[p]){
			continue;
		}
		for(int m = 1; m * p <= n; ++m){
			if(!sieve[m * p]){
				sieve[m * p] = true;
				++cnt;
				if(cnt == k){
					return m * p;
				}
			}
		}
	}
	return -1;
}

int main(){
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		printf("%d\n", solve(n, k));
	}
	return 0;
}
