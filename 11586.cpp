#include <cstdio>
#define MAX (100 + 1)

int main(){
	int n;
	scanf("%d", &n);
	char mirror[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", mirror[i]);
	}
	int k;
	scanf("%d", &k);
	if(k == 1){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%c", mirror[i][j]);
			}
			printf("\n");
		}
	}else if(k == 2){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%c", mirror[i][n - 1 - j]);
			}
			printf("\n");
		}
	}else if(k == 3){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%c", mirror[n - 1 - i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
