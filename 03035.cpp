#include <cstdio>
#define MAX (50 + 1)

int main(){
	int r, c, zr, zc;
	scanf("%d %d %d %d", &r, &c, &zr, &zc);
	char news[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", news[i]);
	}
	for(int i = 0; i < r * zr; ++i){
		for(int j = 0; j < c * zc; ++j){
			printf("%c", news[i / zr][j / zc]);
		}
		printf("\n");
	}
	return 0;
}
