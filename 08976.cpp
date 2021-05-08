#include <cstdio>

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int captures(char board[][10], int x, int y){
	int ret = 0;
	for(int i = 0; i < 8; ++i){
		int nx = x, ny = y;
		int cnt = -1;
		do{
			nx += dx[i];
			ny += dy[i];
			++cnt;
		}while(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == 'W');
		if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == 'B'){
			ret += cnt;
		}
	}
	return ret;
}

int main(){
	char board[10][10];
	for(int i = 0; i < 8; ++i){
		scanf("%s", board[i]);
	}
	int ans = 0;
	for(int x = 0; x < 8; ++x){
		for(int y = 0; y < 8; ++y){
			if(board[x][y] == '.'){
				char board_copy[10][10];
				for(int i = 0; i < 8; ++i){
					for(int j = 0; j < 8; ++j){
						board_copy[i][j] = board[i][j];
					}
				}
				int cmp = captures(board_copy, x, y);
				if(ans < cmp){
					ans = cmp;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
