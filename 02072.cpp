#include <cstdio>

int win(int board[][20], int &x, int &y){
	for(int i = 1; i <= 19; ++i){
		for(int j = 1; j + 4 <= 19; ++j){
			if(board[i][j] != 0 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]
			&& board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4]
			&& !(j + 5 <= 19 && board[i][j] == board[i][j + 5])
			&& !(j - 1 >= 1 && board[i][j] == board[i][j - 1])){
				x = i;
				y = j;
				return board[i][j];
			}
		}
	}
	for(int i = 1; i + 4 <= 19; ++i){
		for(int j = 1; j <= 19; ++j){
			if(board[i][j] != 0 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]
			&& board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j]
			&& !(i + 5 <= 19 && board[i][j] == board[i + 5][j])
			&& !(i - 1 >= 1 && board[i][j] == board[i - 1][j])){
				x = i;
				y = j;
				return board[i][j];
			}
		}
	}
	for(int i = 1; i + 4 <= 19; ++i){
		for(int j = 1; j + 4 <= 19; ++j){
			if(board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]
			&& board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4]
			&& !(i + 5 <= 19 && j + 5 <= 19 && board[i][j] == board[i + 5][j + 5])
			&& !(i - 1 >= 1 && j - 1 >= 1 && board[i][j] == board[i - 1][j - 1])){
				x = i;
				y = j;
				return board[i][j];
			}
		}
	}
	for(int i = 1 + 4; i <= 19; ++i){
		for(int j = 1; j + 4 <= 19; ++j){
			if(board[i][j] != 0 && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2]
			&& board[i][j] == board[i - 3][j + 3] && board[i][j] == board[i - 4][j + 4]
			&& !(i - 5 >= 1 && j + 5 <= 19 && board[i][j] == board[i - 5][j + 5])
			&& !(i + 1 <= 19 && j - 1 >= 1 && board[i][j] == board[i + 1][j - 1])){
				x = i;
				y = j;
				return board[i][j];
			}
		}
	}
	return 0;
}

int main(){
	int board[20][20] = {};
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		if(i % 2 == 1){
			board[x][y] = 1;
		}else{
			board[x][y] = 2;
		}
		int w = win(board, x, y);
		if(w != 0){
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
