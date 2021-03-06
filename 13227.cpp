#include <cstdio>

bool ended(char board[][4]){
	for(int i = 0; i < 3; ++i){
		if(board[i][0] != '.' && board[i][0] == board[i][1] && board[i][0] == board[i][2]){
			return true;
		}
	}
	for(int j = 0; j < 3; ++j){
		if(board[0][j] != '.' && board[0][j] == board[1][j] && board[0][j] == board[2][j]){
			return true;
		}
	}
	if(board[0][0] != '.' && board[0][0] == board[1][1] && board[0][0] == board[2][2]){
		return true;
	}
	if(board[2][0] != '.' && board[2][0] == board[1][1] && board[2][0] == board[0][2]){
		return true;
	}
	return false;
}

int main(){
	char board[3][4];
	for(int i = 0; i < 3; ++i){
		scanf("%s", board[i]);
	}
	printf("%s", ended(board) ? "YES" : "NO");
	return 0;
}
