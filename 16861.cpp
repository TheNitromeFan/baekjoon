#include <cstdio>

int sum_of_digits(int n){
	int ret = 0;
	while(n){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

bool harshad(int n){
	return n % sum_of_digits(n) == 0;
}

int main(){
	int n;
	scanf("%d", &n);
	int x = n;
	while(!harshad(x)){
		++x;
	}
	printf("%d", x);
	return 0;
}
