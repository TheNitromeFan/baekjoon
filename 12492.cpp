#include <cstdio>

bool tile(char grid[][51], int r, int c){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(grid[i][j] == '#'){
				if(i + 1 < r && j + 1 < c && grid[i][j + 1] == '#'
				&& grid[i + 1][j] == '#' && grid[i + 1][j + 1] == '#'){
					grid[i][j] = '/';
					grid[i][j + 1] = '\\';
					grid[i + 1][j] = '\\';
					grid[i + 1][j + 1] = '/';
				}else{
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int r, c;
		scanf("%d %d", &r, &c);
		char grid[51][51];
		for(int i = 0; i < r; ++i){
			scanf("%s", grid[i]);
		}
		printf("Case #%d:\n", a0);
		if(tile(grid, r, c)){
			for(int i = 0; i < r; ++i){
				for(int j = 0; j < c; ++j){
					printf("%c", grid[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("Impossible\n");
		}
	}
	return 0;
}
