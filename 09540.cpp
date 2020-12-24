#include <cstdio>
#define SIZE 10

using namespace std;

int captures(char board[][SIZE + 1], int x, int y, int dx[4], int dy[4]){
	if(x == -1 && y == -1){
		return 0;
	}
	int ret = 0;
	for(int i = 0; i < 4; ++i){
		int nx = x + 2 * dx[i], ny = y + 2 * dy[i];
		int mx = (x + nx) / 2, my = (y + ny) / 2;
		if(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE
		&& board[nx][ny] != 'B' && board[nx][ny] != 'W' && board[mx][my] == 'B'){
			board[x][y] = '.';
			board[nx][ny] = 'W';
			board[mx][my] = '.';
			int cmp = 1 + captures(board, nx, ny, dx, dy);
			if(ret < cmp){
				ret = cmp;
			}
			board[x][y] = 'W';
			board[nx][ny] = '.';
			board[mx][my] = 'B';
		}
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		char board[SIZE + 1][SIZE + 1];
		for(int i = 0; i < SIZE; ++i){
			scanf("%s", board[i]);
		}
		int dx[4] = {1, -1, -1, 1};
		int dy[4] = {1, 1, -1, -1};
		int ans = 0;
		for(int i = 0; i < SIZE; ++i){
			for(int j = 0; j < SIZE; ++j){
				if(board[i][j] == 'W'){
					int cmp = captures(board, i, j, dx, dy);
					if(ans < cmp){
						ans = cmp;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
