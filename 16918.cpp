#include <cstdio>

void simulate(char board[][201], int bomb[][201], int r, int c, int n){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int time = 2; time <= n; ++time){
		if(time % 2 == 0){
			for(int i = 0; i < r; ++i){
				for(int j = 0; j < c; ++j){
					if(bomb[i][j] == 0){
						bomb[i][j] = 2;
					}
				}
			}
		}else{
			bool exploded[201][201] = {};
			for(int i = 0; i < r; ++i){
				for(int j = 0; j < c; ++j){
					if(bomb[i][j] == 1){
						exploded[i][j] = true;
						for(int k = 0; k < 4; ++k){
							int x = i + dx[k], y = j + dy[k];
							if(x >= 0 && x < r && y >= 0 && y < c){
								exploded[x][y] = true;
							}
						}
					}else if(bomb[i][j] == 2){
						bomb[i][j] = 1;
					}
				}
			}
			for(int i = 0; i < r; ++i){
				for(int j = 0; j < c; ++j){
					if(exploded[i][j]){
						bomb[i][j] = 0;
					}
				}
			}
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(bomb[i][j] > 0){
				board[i][j] = 'O';
			}else{
				board[i][j] = '.';
			}
		}
	}
}

int main(){
	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);
	char board[201][201];
	int bomb[201][201] = {};
	for(int i = 0; i < r; ++i){
		scanf("%s", board[i]);
		for(int j = 0; j < c; ++j){
			if(board[i][j] == 'O'){
				bomb[i][j] = 1;
			}
		}
	}
	simulate(board, bomb, r, c, n);
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}
