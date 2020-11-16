#include <cstdio>

bool ttttrow(char board[][5], char x, int row){
	for(int j = 0; j < 4; ++j){
		if(board[row][j] != x && board[row][j] != 'T'){
			return false;
		}
	}
	return true;
}

bool ttttcol(char board[][5], char x, int col){
	for(int i = 0; i < 4; ++i){
		if(board[i][col] != x && board[i][col] != 'T'){
			return false;
		}
	}
	return true;
}

bool ttttdiag1(char board[][5], char x){
	for(int i = 0; i < 4; ++i){
		if(board[i][i] != x && board[i][i] != 'T'){
			return false;
		}
	}
	return true;
}

bool ttttdiag2(char board[][5], char x){
	for(int i = 0; i < 4; ++i){
		if(board[i][3 - i] != x && board[i][3 - i] != 'T'){
			return false;
		}
	}
	return true;
}

bool tttt(char board[][5], char x){
	for(int i = 0; i < 4; ++i){
		if(ttttrow(board, x, i)){
			return true;
		}
	}
	for(int j = 0; j < 4; ++j){
		if(ttttcol(board, x, j)){
			return true;
		}
	}
	return ttttdiag1(board, x) || ttttdiag2(board, x);
}

int result(char board[][5]){
	if(tttt(board, 'X')){
		return 1;
	}else if(tttt(board, 'O')){
		return 2;
	}
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if(board[i][j] == '.'){
				return 4;
			}
		}
	}
	return 3;
}

int main(){
	char board[5][5];
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		for(int x = 0; x < 4; ++x){
			scanf("%s", board[x]);
		}
		printf("Case #%d: ", i);
		int res = result(board);
		if(res == 1){
			printf("X won");
		}else if(res == 2){
			printf("O won");
		}else if(res == 4){
			printf("Game has not completed");
		}else{
			printf("Draw");
		}
		printf("\n");
	}
	return 0;
}
