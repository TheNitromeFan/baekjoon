#include <cstdio>

void print_number(int a){
	if(a >= 0){
		printf("%d", a);
	}else{
		printf("(%d)", a);
	}
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b, diff = a - b, prod = a * b;
	if(sum > diff && sum > prod){
		print_number(a);
		printf("+");
		print_number(b);
		printf("=");
		print_number(sum);
	}else if(diff > sum && diff > prod){
		print_number(a);
		printf("-");
		print_number(b);
		printf("=");
		print_number(diff);
	}else if(prod > sum && prod > diff){
		print_number(a);
		printf("*");
		print_number(b);
		printf("=");
		print_number(prod);
	}else{
		printf("NIE");
	}
	return 0;
}
