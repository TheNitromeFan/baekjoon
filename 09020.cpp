#include <cstdio>

bool is_prime(int n){
	if(n == 2){
		return true;
	}else if(n % 2 == 0){
		return false;
	}
	for(int p = 3; p * p <= n; p += 2){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int a = n/2, b = n/2;
		while(!is_prime(a) || !is_prime(b)){
			--a;
			++b;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}
