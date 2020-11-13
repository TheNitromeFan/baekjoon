#include <cstdio>

bool find_unassigned(int board[][10], int &row, int &col){
	for(row = 1; row <= 9; ++row){
		for(col = 1; col <= 9; ++col){
			if(board[row][col] == 0){
				return true;
			}
		}
	}
	return false;
}

bool is_valid(int board[][10], int row, int column, int num){
	for(int c = 1; c <= 9; ++c){
		if(board[row][c] == num){
			return false;
		}
	}
	for(int r = 1; r <= 9; ++r){
		if(board[r][column] == num){
			return false;
		}
	}
	for(int r = 1; r <= 3; ++r){
		for(int c = 1; c <= 3; ++c){
			if(board[(row-1)/3*3 + r][(column-1)/3*3 + c] == num){
				return false;
			}
		}
	}
	return board[row][column] == 0;
}

bool solve(int board[][10]){
	int row, col;
	if(!find_unassigned(board, row, col)){
		return true;
	}
	for(int num = 1; num <= 9; ++num){
		if(is_valid(board, row, col, num)){
			board[row][col] = num;
			if(solve(board)){
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}

int main(){
	int board[10][10];
	for(int i = 1; i <= 9; ++i){
		for(int j = 1; j <= 9; ++j){
			scanf("%d", &board[i][j]);
		}
	}
	if(solve(board)){
		for(int i = 1; i <= 9; ++i){
			for(int j = 1; j <= 9; ++j){
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("-1");
	}
	return 0;
}
