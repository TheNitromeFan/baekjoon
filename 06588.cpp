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
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int a = 3, b = n-3;
		while(!is_prime(a) || !is_prime(b)){
			a += 2;
			b -= 2;
		}
		printf("%d = %d + %d\n", n, a, b);
	}
	return 0;
}
