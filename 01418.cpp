#include <cstdio>

bool good(int n, int k){
	for(int p = 2; p * p <= n; ++p){
		if(p > k && n % p == 0){
			return false;
		}
		while(n % p == 0){
			n /= p;
		}
	}
	return n <= k;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(good(i, k)){
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}
