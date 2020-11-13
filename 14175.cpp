#include <cstdio>

int main(){
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	char paper[10][11];
	for(int i = 0; i < m; ++i){
		scanf("%s", paper[i]);
	}
	for(int i = 0; i < m * k; ++i){
		for(int j = 0; j < n * k; ++j){
			printf("%c", paper[i / k][j / k]);
		}
		printf("\n");
	}
	return 0;
}
