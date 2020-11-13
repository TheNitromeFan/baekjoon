#include <cstdio>

int main(){
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if((i + j) % 2 == (r + c) % 2){
				printf("v");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
