#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	n /= 52 * 7;
	if(n - 3 <= 100){
		printf("%d\n%d", n - 3, 1);
	}else if(n % 3 == 1){
		printf("100\n%d", (n - 100) / 3);
	}else if(n % 3 == 0){
		printf("99\n%d", (n - 99) / 3);
	}else{
		printf("98\n%d", (n - 98) / 3);
	}
	return 0;
}
