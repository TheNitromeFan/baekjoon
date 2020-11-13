#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 1; a0 <= n; ++a0){
		int row, col, w, h;
		scanf("%d %d %d %d", &row, &col, &w, &h);
		printf("Case #%d:\n", a0);
		for(int i = 0; i <= row * (h + 1); ++i){
			for(int j = 0; j <= col * (w + 1); ++j){
				if(i % (h + 1) == 0 && j % (w + 1) == 0){
					printf("+");
				}else if(i % (h + 1) == 0){
					printf("-");
				}else if(j % (w + 1) == 0){
					printf("|");
				}else{
					printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
