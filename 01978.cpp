#include <cstdio>


int is_prime(int number){
	
	if(number == 1 || (number != 2 && number % 2 == 0)) return 0;
	for(int p = 3; p*p <= number; p += 2)
		if(number % p == 0) return 0;
	return 1;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	int count = 0;
	for(int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		count += is_prime(num);
	}
	printf("%d", count);
	return 0;
}
