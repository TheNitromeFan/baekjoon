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

void goldbach(int n){
	if(n == 4){
		printf("2 2");
		return;
	}
	int a = 3, b = n - 3;
	while(!is_prime(a) || !is_prime(b)){
		a += 2;
		b -= 2;
	}
	printf("%d %d", a, b);
}

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 7){
		printf("-1");
		return 0;
	}
	if(n % 2 == 0){
		printf("2 2 ");
		goldbach(n - 4);
	}else{
		printf("2 3 ");
		goldbach(n - 5);
	}
	return 0;
}
