#include <cstdio>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	a %= 10;
	if(a == 0 || a == 1 || a == 5 || a == 6){
		printf("%d", a);
	}else if(a == 4 || a == 9){
		b %= 2;
		if(b == 1){
			printf("%d", a);
		}else{
			printf("%d", a * a % 10);
		}
	}else{
		b %= 4;
		if(b == 1){
			printf("%d", a);
		}else if(b == 2){
			printf("%d", a * a % 10);
		}else if(b == 3){
			printf("%d", a * a * a % 10);
		}else{
			printf("%d", a * a * a * a % 10);
		}
	}
	return 0;
}
