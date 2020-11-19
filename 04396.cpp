#include <cstdio>

void solve(char board[][11], char mined[][11], char output[][11], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			output[i][j] = '.';
		}
	}
	int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	bool touched = false;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(mined[i][j] == '.'){
				continue;
			}
			if(board[i][j] == '*'){
				touched = true;
				continue;
			}
			int cnt = 0;
			for(int k = 0; k < 8; ++k){
				int x = i + dx[k], y = j + dy[k];
				if(x >= 0 && x < n && y >= 0 && y < n && board[x][y] == '*'){
					++cnt;
				}
			}
			output[i][j] = '0' + cnt;
		}
	}
	if(touched){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(board[i][j] == '*'){
					output[i][j] = '*';
				}
			}
		}
	}
}

int main(){
	int n;
	char board[11][11];
	char mined[11][11];
	char output[11][11] = {};
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%s", mined[i]);
	}
	solve(board, mined, output, n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%c", output[i][j]);
		}
		printf("\n");
	}
	return 0;
}
