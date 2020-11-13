#include <cstdio>

bool ttt1(char board[][4], char x){
	for(int i = 0; i < 3; ++i){
		if(board[i][0] == x && board[i][1] == x && board[i][2] == x){
			return true;
		}
	}
	for(int j = 0; j < 3; ++j){
		if(board[0][j] == x && board[1][j] == x && board[2][j] == x){
			return true;
		}
	}
	if(board[0][0] == x && board[1][1] == x && board[2][2] == x){
		return true;
	}
	if(board[0][2] == x && board[1][1] == x && board[2][0] == x){
		return true;
	}
	return false;
}

bool ttt2(char board[][4], char x, char y){
	for(int i = 0; i < 3; ++i){
		if(board[i][0] == x && board[i][1] == x && board[i][2] == x){
			continue;
		}
		if(board[i][0] == y && board[i][1] == y && board[i][2] == y){
			continue;
		}
		if((board[i][0] == x || board[i][0] == y)
		&& (board[i][1] == x || board[i][1] == y)
		&& (board[i][2] == x || board[i][2] == y)){
			return true;
		}
	}
	for(int j = 0; j < 3; ++j){
		if(board[0][j] == x && board[1][j] == x && board[2][j] == x){
			continue;
		}
		if(board[0][j] == y && board[1][j] == y && board[2][j] == y){
			continue;
		}
		if((board[0][j] == x || board[0][j] == y)
		&& (board[1][j] == x || board[1][j] == y)
		&& (board[2][j] == x || board[2][j] == y)){
			return true;
		}
	}
	if(!(board[0][0] == x && board[1][1] == x && board[2][2] == x)
	&& !(board[0][0] == y && board[1][1] == y && board[2][2] == y)
	&& (board[0][0] == x || board[0][0] == y)
	&& (board[1][1] == x || board[1][1] == y)
	&& (board[2][2] == x || board[2][2] == y)){
		return true;
	}
	if(!(board[0][2] == x && board[1][1] == x && board[2][0] == x)
	&& !(board[0][2] == y && board[1][1] == y && board[2][0] == y)
	&& (board[0][2] == x || board[0][2] == y)
	&& (board[1][1] == x || board[1][1] == y)
	&& (board[2][0] == x || board[2][0] == y)){
		return true;
	}
	return false;
}

int main(){
	char board[4][4];
	for(int i = 0; i < 3; ++i){
		scanf("%s", board[i]);
	}
	int cnt = 0;
	for(char x = 'A'; x <= 'Z'; ++x){
		if(ttt1(board, x)){
			++cnt;
		}
	}
	printf("%d\n", cnt);
	cnt = 0;
	for(char x = 'A'; x <= 'Z'; ++x){
		for(char y = 'A'; y < x; ++y){
			if(ttt2(board, x, y)){
				++cnt;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
