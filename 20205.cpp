#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[10][10];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < k * n; ++i){
		for(int j = 0; j < k * n; ++j){
			printf("%d ", a[i / k][j / k]);
		}
		printf("\n");
	}
	return 0;
}
