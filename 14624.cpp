#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n % 2 == 0){
		printf("I LOVE CBNU");
		return 0;
	}
	for(int j = 0; j < n; ++j){
		printf("*");
	}
	printf("\n");
	for(int j = 0; j < n / 2; ++j){
		printf(" ");
	}
	printf("*");
	printf("\n");
	for(int i = n / 2 - 1; i >= 0; --i){
		for(int j = 0; j < i; ++j){
			printf(" ");
		}
		printf("*");
		for(int j = 0; j < n - 2 * i - 2; ++j){
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	return 0;
}
