#include <cstdio>

bool wins(char board[][4], char shape){
	// rows
	for(int i = 0; i < 3; ++i){
		if(board[i][0] == shape && board[i][1] == shape && board[i][2] == shape){
			return true;
		}
	}
	for(int j = 0; j < 3; ++j){
		if(board[0][j] == shape && board[1][j] == shape && board[2][j] == shape){
			return true;
		}
	}
	if(board[0][0] == shape && board[1][1] == shape && board[2][2] == shape){
		return true;
	}
	if(board[0][2] == shape && board[1][1] == shape && board[2][0] == shape){
		return true;
	}
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		printf("Case %d:\n", a0);
		char board[4][4];
		for(int i = 0; i < 3; ++i){
			scanf("%s", board[i]);
		}
		char shape;
		char line[4];
		scanf("%s", line);
		shape = line[0];
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				if(board[i][j] == '-'){
					board[i][j] = shape;
					if(wins(board, shape)){
						for(int x = 0; x < 3; ++x){
							for(int y = 0; y < 3; ++y){
								printf("%c", board[x][y]);
							}
							printf("\n");
						}
					}
					board[i][j] = '-';
				}
			}
		}
	}
	return 0;
}
