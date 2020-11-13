#include <cstdio>
#define MAX 31

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void winner(char board[][MAX], int sz){
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			for(int d = 0; d < 8; ++d){
				if(i + dx[d] * 2 >= 0 && i + dx[d] * 2 < sz && j + dy[d] * 2 >= 0 && j + dy[d] * 2 < sz
				&& board[i][j] == board[i + dx[d]][j + dy[d]] && board[i][j] == board[i + dx[d] * 2][j + dy[d] * 2]
				&& board[i][j] != '.'){
					printf("%c", board[i][j]);
					return;
				}
			}
		}
	}
	printf("ongoing");
}

int main(){
	int n;
	scanf("%d", &n);
	char board[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	winner(board, n);
	return 0;
}
