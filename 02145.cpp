#include <cstdio>

int sum_of_digits(int n){
	int ret = 0;
	while(n > 0){
		ret += n % 10;
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
		while(n >= 10){
			n = sum_of_digits(n);
		}
		printf("%d\n", n);
	}
	return 0;
}
