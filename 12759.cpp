#include <cstdio>

int tictactoe(int board[][3]){
	for(int i = 0; i < 3; ++i){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0){
			return board[i][0];
		}
	}
	for(int j = 0; j < 3; ++j){
		if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != 0){
			return board[0][j];
		}
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0){
		return board[0][0];
	}
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != 0){
		return board[2][0];
	}
	return 0;
}

int main(){
	int board[3][3] = {};
	int player;
	scanf("%d", &player);
	for(int i = 0; i < 9; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		board[x - 1][y - 1] = player;
		int ans = tictactoe(board);
		if(ans != 0){
			printf("%d", ans);
			return 0;
		}
		player = 3 - player;
	}
	printf("0");
	return 0;
}
