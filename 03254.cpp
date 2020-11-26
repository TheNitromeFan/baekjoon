#include <cstdio>

void insert(int board[][7], int col, int x){
	board[0][col] = x;
	for(int i = 0; i + 1 < 6 && board[i + 1][col] == 0; ++i){
		board[i + 1][col] = x;
		board[i][col] = 0;
	}
}

bool won(int board[][7], int x){
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j + 3 < 7; ++j){
			if(board[i][j] == x && board[i][j + 1] == x && board[i][j + 2] == x && board[i][j + 3] == x){
				return true;
			}
		}
	}
	for(int i = 0; i + 3 < 6; ++i){
		for(int j = 0; j < 7; ++j){
			if(board[i][j] == x && board[i + 1][j] == x && board[i + 2][j] == x && board[i + 3][j] == x){
				return true;
			}
		}
	}
	for(int i = 0; i + 3 < 6; ++i){
		for(int j = 0; j + 3 < 7; ++j){
			if(board[i][j] == x && board[i + 1][j + 1] == x && board[i + 2][j + 2] == x && board[i + 3][j + 3] == x){
				return true;
			}
		}
	}
	for(int i = 0; i + 3 < 6; ++i){
		for(int j = 0; j + 3 < 7; ++j){
			if(board[i][j + 3] == x && board[i + 1][j + 2] == x && board[i + 2][j + 1] == x && board[i + 3][j] == x){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int board[6][7] = {};
	for(int i = 1; i <= 21; ++i){
		int mi;
		scanf("%d", &mi);
		insert(board, mi - 1, 1);
		if(won(board, 1)){
			printf("sk %d", i);
			return 0;
		}
		int si;
		scanf("%d", &si);
		insert(board, si - 1, 2);
		if(won(board, 2)){
			printf("ji %d", i);
			return 0;
		}
		/*
		for(int i = 0; i < 6; ++i){
			for(int j = 0; j < 7; ++j){
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
		*/
	}
	printf("ss");
	return 0;
}
