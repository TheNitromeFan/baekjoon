#include <cstdio>
#define MOD 1000000007

long long factorial(int n){
	if(n == 1){
		return 1LL;
	}else{
		return n * factorial(n-1) % MOD;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		printf("%lld\n", factorial(n) - 1);
	}
	return 0;
}
