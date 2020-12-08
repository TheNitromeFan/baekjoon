#include <cstdio>

int main(){
	int n, m, x;
	scanf("%d %d %d", &n, &m, &x);
	int h[100001];
	for(int j = 1; j <= m; ++j){
		scanf("%d", &h[j]);
	}
	for(int i = n; i >= 1; --i){
		for(int j = 1; j <= m; ++j){
			if(i == x){
				if(h[j] >= x){
					printf("*");
				}else{
					printf("-");
				}
			}else if(i < x){
				if(h[j] >= i){
					printf("#");
				}else if(j % 3 == 0){
					printf("|");
				}else{
					printf(".");
				}
			}else{
				if(h[j] >= i){
					printf("#");
				}else{
					printf(".");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
