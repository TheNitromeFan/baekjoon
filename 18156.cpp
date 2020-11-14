#include <cstdio>

bool correct(char grid[][25], int n){
	for(int i = 0; i < n; ++i){
		int black = 0, white = 0;
		for(int j = 0; j < n; ++j){
			if(grid[i][j] == 'B'){
				++black;
			}else{
				++white;
			}
		}
		if(black != white){
			return false;
		}
	}
	for(int j = 0; j < n; ++j){
		int black = 0, white = 0;
		for(int i = 0; i < n; ++i){
			if(grid[i][j] == 'B'){
				++black;
			}else{
				++white;
			}
		}
		if(black != white){
			return false;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j + 2 < n; ++j){
			if(grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2]){
				return false;
			}
		}
	}
	for(int j = 0; j < n; ++j){
		for(int i = 0; i + 2 < n; ++i){
			if(grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	char grid[25][25];
	for(int i = 0; i < n; ++i){
		scanf("%s", grid[i]);
	}
	printf("%d", correct(grid, n));
	return 0;
}
