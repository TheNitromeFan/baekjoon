#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n == 1){
		printf("*");
		return 0;
	}
	int len = 4 * n - 3;
	for(int j = 0; j < len; ++j){
		printf("*");
	}
	printf("\n");
	printf("*");
	printf("\n");
	for(int i = 0; i < len - 1; ++i){
		int k;
		if(i == len / 2 - 1){
			for(int j = 0; j < len - 1; j += 2){
				printf("* ");
			}
			printf("*");
		}else if(i % 2 == 0){
			if(i < len / 2){
				k = i / 2 + 1;
				for(int j = 0; j < 2 * k; j += 2){
					printf("* ");
				}
				for(int j = 2 * k; j < len - 2 * k + 2; ++j){
					printf("*");
				}
				for(int j = len - 2 * k + 2; j < len; j += 2){
					printf(" *");
				}
			}else{
				k = (len - i) / 2;
				for(int j = 0; j < 2 * k; j += 2){
					printf("* ");
				}
				for(int j = 2 * k; j < len - 2 * k; ++j){
					printf("*");
				}
				for(int j = len - 2 * k; j < len; j += 2){
					printf(" *");
				}
			}
		}else{
			if(i < len / 2){
				k = (i + 1) / 2 + 1;
				for(int j = 0; j < 2 * k; j += 2){
					printf("* ");
				}
				for(int j = 2 * k; j < len - 2 * k + 2; ++j){
					printf(" ");
				}
				for(int j = len - 2 * k + 2; j < len; j += 2){
					printf(" *");
				}
			}else{
				k = (len - i) / 2;
				for(int j = 0; j < 2 * k; j += 2){
					printf("* ");
				}
				for(int j = 2 * k; j < len - 2 * k; ++j){
					printf(" ");
				}
				for(int j = len - 2 * k; j < len; j += 2){
					printf(" *");
				}
			}
		}
		printf("\n");
	}
	for(int j = 0; j < len; ++j){
		printf("*");
	}
	return 0;
}
