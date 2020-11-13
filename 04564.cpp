#include <cstdio>

int digit_product(int n){
	int ret = 1;
	while(n){
		ret *= n % 10;
		n /= 10;
	}
	return ret;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		while(true){
			printf("%d ", n);
			if(n < 10){
				break;
			}
			n = digit_product(n);
		}
		printf("\n");
	}
	return 0;
}
