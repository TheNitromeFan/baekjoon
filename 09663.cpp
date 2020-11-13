#include <cstdio>

bool board[15][15] = {};

bool is_safe(int size, int row, int column){
	for(int i = column; i >= 0; i--)
		if(board[row][i])
			return false;
	for(int i = row, j = column; i >= 0 && j >= 0; i--, j--)
		if(board[i][j])
			return false;
	for(int i = row, j = column; i < size && j >= 0; i++, j--)
		if(board[i][j])
			return false;
	return true;
}

int solve(int size, int column){
	if(column == size){
		return 1;
	}
	int count = 0;
	for(int i = 0; i < size; i++)
		if(is_safe(size, i, column)){
			board[i][column] = true;
			count += solve(size, column+1);
			board[i][column] = false;
		}
	return count;
}

int main(void){
	int n;
	scanf("%d", &n);
	printf("%d", solve(n, 0));
	return 0;
}
