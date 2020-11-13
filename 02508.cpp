#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		char board[401][401];
		int r, c;
		scanf("%d %d", &r, &c);
		for(int i = 0; i < r; ++i){
			scanf("%s", board[i]);
		}
		int ans = 0;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c - 2; ++j){
				if(board[i][j] == '>' && board[i][j + 1] == 'o' && board[i][j + 2] == '<'){
					++ans;
				}
			}
		}
		for(int i = 0; i < r - 2; ++i){
			for(int j = 0; j < c; ++j){
				if(board[i][j] == 'v' && board[i + 1][j] == 'o' && board[i + 2][j] == '^'){
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
