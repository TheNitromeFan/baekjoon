#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n == 1){
		printf("*");
		return 0;
	}
	for(int i = 1; i <= 2*n; ++i){
		if(i % 2 == 0){
			printf(" ");
		}
		for(int j = 1; j < (n + (i % 2))/2; ++j){
			printf("* ");
		}
		printf("*\n");
	}
	return 0;
}
