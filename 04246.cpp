#include <cstdio>
#include <cstring>

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		char columns[300][300] = {};
		char code[300] = {};
		scanf("%s", code);
		int len = strlen(code);
		for(int i = 0; i < len / n; ++i){
			for(int j = 0; j < n; ++j){
				if(i % 2 == 0){
					columns[i][j] = code[i * n + j];
				}else{
					columns[i][n - 1 - j] = code[i * n + j];
				}
			}
		}
		for(int j = 0; j < n; ++j){
			for(int i = 0; i < len / n; ++i){
				printf("%c", columns[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
