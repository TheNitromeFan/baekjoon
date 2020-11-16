#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		if(i % 2 == 0){
			for(int j = 1; j <= n; ++j){
				printf("%d ", n * i + j);
			}
		}else{
			for(int j = 1; j <= n; ++j){
				printf("%d ", n * i + (n + 1 - j));
			}
		}
		printf("\n");
	}
	return 0;
}
