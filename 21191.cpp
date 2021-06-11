#include <cstdio>
#define MAX (24 + 1)

bool correct(char board[][MAX], int n){
	for(int i = 0; i < n; ++i){
		int white = 0;
		for(int j = 0; j < n; ++j){
			if(board[i][j] == 'W'){
				++white;
			}
		}
		if(2 * white != n){
			return false;
		}
	}
	for(int j = 0; j < n; ++j){
		int white = 0;
		for(int i = 0; i < n; ++i){
			if(board[i][j] == 'W'){
				++white;
			}
		}
		if(2 * white != n){
			return false;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j + 2 < n; ++j){
			if(board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]){
				return false;
			}
		}
	}
	for(int j = 0; j < n; ++j){
		for(int i = 0; i + 2 < n; ++i){
			if(board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	char board[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	printf("%d", correct(board, n));
	return 0;
}
