#include <cstdio>

bool winnable(char board[][11]){
	for(int x = 0; x < 10; ++x){
		for(int y = 0; y < 6; ++y){
			int cnt = 0, empty = 0;
			for(int j = y; j < y + 5; ++j){
				if(board[x][j] == 'X'){
					++cnt;
				}else if(board[x][j] == '.'){
					++empty;
				}
			}
			if(cnt == 4 && empty == 1){
				return true;
			}
		}
	}
	for(int y = 0; y < 10; ++y){
		for(int x = 0; x < 6; ++x){
			int cnt = 0, empty = 0;
			for(int i = x; i < x + 5; ++i){
				if(board[i][y] == 'X'){
					++cnt;
				}else if(board[i][y] == '.'){
					++empty;
				}
			}
			if(cnt == 4 && empty == 1){
				return true;
			}
		}
	}
	for(int x = 0; x < 6; ++x){
		for(int y = 0; y < 6; ++y){
			int cnt = 0, empty = 0;
			for(int i = x, j = y; i < x + 5 && j < y + 5; ++i, ++j){
				if(board[i][j] == 'X'){
					++cnt;
				}else if(board[i][j] == '.'){
					++empty;
				}
			}
			if(cnt == 4 && empty == 1){
				return true;
			}
		}
	}
	for(int x = 4; x < 10; ++x){
		for(int y = 0; y < 6; ++y){
			int cnt = 0, empty = 0;
			for(int i = x, j = y; i > x - 5 && j < y + 5; --i, ++j){
				if(board[i][j] == 'X'){
					++cnt;
				}else if(board[i][j] == '.'){
					++empty;
				}
			}
			if(cnt == 4 && empty == 1){
				return true;
			}
		}
	}
	return false;
}

int main(){
	char board[10][11];
	for(int i = 0; i < 10; ++i){
		scanf("%s", board[i]);
	}
	printf("%d", winnable(board));
	return 0;
}
