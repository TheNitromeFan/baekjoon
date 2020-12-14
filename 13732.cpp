#include <cstdio>
#define MAXR 50001
#define MAXC 11

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[MAXR][MAXC];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	char final[MAXR][MAXC];
	for(int j = 0; j < c; ++j){
		int apples = 0;
		for(int row = 0; row < r; ++row){
			if(map[row][j] == '#'){
				final[row][j] = '#';
				for(int i = row - 1; apples > 0; --i, --apples){
					final[i][j] = 'a';
				}
			}else if(map[row][j] == 'a'){
				++apples;
				final[row][j] = '.';
			}else{
				final[row][j] = '.';
			}
		}
		for(int i = r - 1; apples > 0; --i, --apples){
			final[i][j] = 'a';
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%c", final[i][j]);
		}
		printf("\n");
	}
	return 0;
}
