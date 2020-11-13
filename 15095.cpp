#include <cstdio>

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool valid(char board[][6]){
	int knights = 0;
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(board[i][j] == 'k'){
				for(int k = 0; k < 8; ++k){
					int x = i + dx[k], y = j + dy[k];
					if(x >= 0 && x < 5 && y >= 0 && y < 5 && board[x][y] == 'k'){
						return false;
					}
				}
				++knights;
			}
		}
	}
	return knights == 9;
}

int main(){
	char board[5][6];
	for(int i = 0; i < 5; ++i){
		scanf("%s", board[i]);
	}
	printf("%s", valid(board) ? "valid" : "invalid");
	return 0;
}
