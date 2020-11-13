#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int j = 0; j < n; ++j){
		printf("*");
	}
	for(int j = n; j < 3 * n - 3; ++j){
		printf(" ");
	}
	for(int j = 3 * n - 3; j < 4 * n - 3; ++j){
		printf("*");
	}
	printf("\n");
	for(int i = 1; i < n - 1; ++i){
		for(int j = 0; j < i; ++j){
			printf(" ");
		}
		printf("*");
		for(int j = 0; j < n - 2; ++j){
			printf(" ");
		}
		printf("*");
		for(int j = 0; j < 2 * n - 2 * i - 3; ++j){
			printf(" ");
		}
		printf("*");
		for(int j = 0; j < n - 2; ++j){
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	for(int j = 0; j < n - 1; ++j){
		printf(" ");
	}
	printf("*");
	for(int j = 0; j < n - 2; ++j){
		printf(" ");
	}
	printf("*");
	for(int j = 0; j < n - 2; ++j){
		printf(" ");
	}
	printf("*");
	printf("\n");
	for(int i = n - 2; i > 0; --i){
		for(int j = 0; j < i; ++j){
			printf(" ");
		}
		printf("*");
		for(int j = 0; j < n - 2; ++j){
			printf(" ");
		}
		printf("*");
		for(int j = 0; j < 2 * n - 2 * i - 3; ++j){
			printf(" ");
		}
		printf("*");
		for(int j = 0; j < n - 2; ++j){
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	for(int j = 0; j < n; ++j){
		printf("*");
	}
	for(int j = n; j < 3 * n - 3; ++j){
		printf(" ");
	}
	for(int j = 3 * n - 3; j < 4 * n - 3; ++j){
		printf("*");
	}
	return 0;
}
