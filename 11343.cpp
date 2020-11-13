#include <cstdio>

void solve(){
	char line[301];
	int r, c;
	scanf("%d %d", &r, &c);
	fgets(line, 300, stdin);
	char board[101][101];
	for(int i = 1; i <= r; ++i){
		fgets(line, 300, stdin);
		for(int j = 1; j <= c; ++j){
			board[i][j] = line[(j - 1) * 2];
		}
	}
	// search rows
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= c-2; ++j){
			if(board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]){
				printf("%d %d %d %d %d %d\n", i, j, i, j+1, i, j+2);
				return;
			}
		}
	}
	// search columns
	for(int j = 1; j <= c; ++j){
		for(int i = 1; i <= r-2; ++i){
			if(board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j]){
				printf("%d %d %d %d %d %d\n", i, j, i+1, j, i+2, j);
				return;
			}
		}
	}
	// none found
	printf("no set found\n");
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		solve();
	}
	return 0;
}
