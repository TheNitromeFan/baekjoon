#include <cstdio>
#include <cstring>
#define MAX ((1 << 15) + 1)

void sieve(bool p[MAX]){
	memset(p, true, MAX * sizeof(bool));
	p[0] = false;
	p[1] = false;
	for(int i = 2; i * i < MAX; ++i){
		if(!p[i]){
			continue;
		}
		for(int m = i; m * i < MAX; ++m){
			p[m * i] = false;
		}
	}
}

int main(){
	bool primes[MAX];
	sieve(primes);
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int ans = 0;
		for(int i = 3, j = n - 3; i <= j; i += 2, j -= 2){
			if(primes[i] && primes[j]){
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
