#include <cstdio>

int main(){
	int x = 0;
	for(int i = 0; i < 20; ++i){
		printf("58");
		for(int j = 0; j < 58; ++j){
			++x;
			printf(" %d", x);
		}
		printf("\n");
	}
	for(int i = 20; i < 140; ++i){
		printf("57");
		for(int j = 0; j < 57; ++j){
			++x;
			printf(" %d", x);
		}
		printf("\n");
	}
	return 0;
}
