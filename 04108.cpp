#include <cstdio>

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int adj(char board[][101], int r, int c, int x, int y){
	int ret = 0;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == '*'){
			++ret;
		}
	}
	return ret;
}

int main(){
	while(true){
		int r, c;
		scanf("%d %d", &r, &c);
		if(r == 0 && c == 0){
			break;
		}
		char board[101][101];
		for(int i = 0; i < r; ++i){
			scanf("%s", board[i]);
		}
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				if(board[i][j] != '*'){
					board[i][j] = adj(board, r, c, i, j) + '0';
				}
				printf("%c", board[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
