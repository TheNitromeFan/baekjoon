#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int j = 0; j < n-1; ++j){
		printf(" ");
	}
	printf("*");
	printf("\n");
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < n-i-1; ++j){
			printf(" ");
		}
		printf("*");
		for(int j = 0; j < 2*i-1; ++j){
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	return 0;
}
