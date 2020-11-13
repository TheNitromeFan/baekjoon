#include <cstdio>

int sum_of_squared_digits(int n){
	int ret = 0;
	while(n){
		ret += (n % 10) * (n % 10);
		n /= 10;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	while(true){
		if(n == 1){
			printf("HAPPY");
			break;
		}else if(n == 4){
			printf("UNHAPPY");
			break;
		}
		n = sum_of_squared_digits(n);
	}
	return 0;
}
