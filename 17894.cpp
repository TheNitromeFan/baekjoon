#include <cstdio>
#define MAX 101

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] == '.' && !(i > 0 && map[i - 1][j] == 'E') && !(j > 0 && map[i][j - 1] == 'E')){
				map[i][j] = 'E';
			}
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
