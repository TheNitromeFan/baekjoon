#include <cstdio>

int main(){
	int k;
	scanf("%d", &k);
	int grass[11][11];
	for(int i = 1; i <= 10; ++i){
		for(int j = 1; j <= 10; ++j){
			grass[i][j] = 1;
		}
	}
	for(int a0 = 0; a0 < k; ++a0){
		for(int i = 1; i <= 10; ++i){
			for(int j = 1; j <= 10; ++j){
				++grass[i][j];
			}
		}
		int r1, r2, r3, c1, c2, c3;
		scanf("%d %d %d %d %d %d", &r1, &r2, &r3, &c1, &c2, &c3);
		for(int j = 1; j <= 10; ++j){
			grass[r1][j] = 1;
		}
		for(int j = 1; j <= 10; ++j){
			grass[r2][j] = 1;
		}
		for(int j = 1; j <= 10; ++j){
			grass[r3][j] = 1;
		}
		for(int i = 1; i <= 10; ++i){
			grass[i][c1] = 1;
		}
		for(int i = 1; i <= 10; ++i){
			grass[i][c2] = 1;
		}
		for(int i = 1; i <= 10; ++i){
			grass[i][c3] = 1;
		}
	}
	for(int i = 1; i <= 10; ++i){
		for(int j = 1; j <= 10; ++j){
			printf("%d ", grass[i][j]);
		}
		printf("\n");
	}
	return 0;
}
