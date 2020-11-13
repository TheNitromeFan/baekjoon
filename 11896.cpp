#include <cstdio>

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	if(b <= 3){
		printf("0");
		return 0;
	}else if(a <= 3){
		a = 4;
	}else if(a % 2 == 1){
		++a;
	}
	if(b % 2 == 1){
		--b;
	}
	printf("%lld", (a + b) / 2 * (b / 2 - a / 2 + 1));
	return 0;
}
