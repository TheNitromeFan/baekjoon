#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int r, c;
		scanf("%d %d", &r, &c);
		char grid[26][26];
		int first_row = -1;
		for(int i = 0; i < r; ++i){
			scanf("%s", grid[i]);
			for(int j = 0; j < c; ++j){
				if(first_row == -1 && grid[i][j] != '?'){
					first_row = i;
				}
			}
		}
		for(int i = first_row; i < r; ++i){
			int first_col = -1;
			for(int j = 0; j < c; ++j){
				if(first_col == -1 && grid[i][j] != '?'){
					first_col = j;
				}
			}
			if(first_col != -1){
				for(int j = 0; j < first_col; ++j){
					grid[i][j] = grid[i][first_col];
				}
				for(int j = first_col; j < c; ++j){
					if(grid[i][j] == '?'){
						grid[i][j] = grid[i][j - 1];
					}
				}
			}else{
				for(int j = 0; j < c; ++j){
					grid[i][j] = grid[i - 1][j];
				}
			}
		}
		for(int i = first_row - 1; i >= 0; --i){
			for(int j = 0; j < c; ++j){
				grid[i][j] = grid[i + 1][j];
			}
		}
		printf("Case #%d:\n", a0);
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				printf("%c", grid[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
