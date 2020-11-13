#include <cstdio>

void draw(int n){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= i; ++j){
			printf("*");
		}
		printf("\n");
	}
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		draw(n);
	}
	return 0;
}
