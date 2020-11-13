#include <cstdio>

void factorize(int n){
	for(int p = 2; p * p <= n; ++p){
		if(n % p != 0){
			continue;
		}
		int cnt = 0;
		while(n % p == 0){
			++cnt;
			n /= p;
		}
		printf("%d %d\n", p, cnt);
	}
	if(n > 1){
		printf("%d %d\n", n, 1);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		factorize(n);
	}
	return 0;
}
