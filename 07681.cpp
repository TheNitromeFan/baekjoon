#include <cstdio>

bool find_unassigned(char board[][10], int &row, int &col){
	for(row = 0; row < 9; ++row){
		for(col = 0; col < 9; ++col){
			if(board[row][col] == '.'){
				return true;
			}
		}
	}
	return false;
}

bool is_valid(char board[][10], int row, int column, char num){
	for(int c = 0; c < 9; ++c){
		if(board[row][c] == num){
			return false;
		}
	}
	for(int r = 0; r < 9; ++r){
		if(board[r][column] == num){
			return false;
		}
	}
	for(int r = 0; r < 3; ++r){
		for(int c = 0; c < 3; ++c){
			if(board[row / 3 * 3 + r][column / 3 * 3 + c] == num){
				return false;
			}
		}
	}
	return board[row][column] == '.';
}

bool solve(char board[][10]){
	int row, col;
	if(!find_unassigned(board, row, col)){
		return true;
	}
	for(char num = '1'; num <= '9'; ++num){
		if(is_valid(board, row, col, num)){
			board[row][col] = num;
			if(solve(board)){
				return true;
			}
			board[row][col] = '.';
		}
	}
	return false;
}

int main(){
	while(true){
		char board[10][10];
		char line[82];
		scanf("%s", line);
		if(line[0] == 'e'){
			break;
		}
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				board[i][j] = line[i * 9 + j];
			}
		}
		if(solve(board)){
			for(int i = 0; i < 9; ++i){
				for(int j = 0; j < 9; ++j){
					printf("%c", board[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
