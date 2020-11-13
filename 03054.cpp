#include <cstdio>
#include <cstring>

int main(){
	char word[16];
	scanf("%s", word);
	int n = strlen(word);
	for(int i = 0; i < 4*n + 1; ++i){
		if(i % 4 == 2 && (i - 2) / 4 % 3 == 2){
			printf("*");
		}else if(i % 4 == 2){
			printf("#");
		}else{
			printf(".");
		}
	}
	printf("\n");
	for(int i = 0; i < 4*n + 1; ++i){
		if(i % 4 == 1 && (i - 1) / 4 % 3 == 2){
			printf("*");
		}else if(i % 4 == 1){
			printf("#");
		}else if(i % 4 == 3 && (i - 3) / 4 % 3 == 2){
			printf("*");
		}else if(i % 4 == 3){
			printf("#");
		}else{
			printf(".");
		}
	}
	printf("\n");
	for(int i = 0; i < 4*n + 1; ++i){
		if(i % 4 == 2){
			printf("%c", word[(i - 2) / 4]);
		}else if(i % 4 == 0 && ((i > 0 && (i - 4) / 4 % 3 == 2) || (i < 4*n && i / 4 % 3 == 2))){
			printf("*");
		}else if(i % 4 == 0){
			printf("#");
		}else{
			printf(".");
		}
	}
	printf("\n");
	for(int i = 0; i < 4*n + 1; ++i){
		if(i % 4 == 1 && (i - 1) / 4 % 3 == 2){
			printf("*");
		}else if(i % 4 == 1){
			printf("#");
		}else if(i % 4 == 3 && (i - 3) / 4 % 3 == 2){
			printf("*");
		}else if(i % 4 == 3){
			printf("#");
		}else{
			printf(".");
		}
	}
	printf("\n");
	for(int i = 0; i < 4*n + 1; ++i){
		if(i % 4 == 2 && (i - 2) / 4 % 3 == 2){
			printf("*");
		}else if(i % 4 == 2){
			printf("#");
		}else{
			printf(".");
		}
	}
	return 0;
}
