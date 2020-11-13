#include <cstdio>
#include <cstring>

bool correct(int board[][9]){
	bool used[10] = {};
	// rows
	for(int i = 0; i < 9; ++i){
		memset(used, false, 10);
		for(int j = 0; j < 9; ++j){
			if(used[board[i][j]]){
				return false;
			}else{
				used[board[i][j]] = true;
			}
		}
	}
	// columns
	for(int j = 0; j < 9; ++j){
		memset(used, false, 10);
		for(int i = 0; i < 9; ++i){
			if(used[board[i][j]]){
				return false;
			}else{
				used[board[i][j]] = true;
			}
		}
	}
	// boxes
	for(int x = 0; x < 3; ++x){
		for(int y = 0; y < 3; ++y){
			memset(used, false, 10);
			for(int i = 3 * x; i < 3 * x + 3; ++i){
				for(int j = 3 * y; j < 3 * y + 3; ++j){
					if(used[board[i][j]]){
						return false;
					}else{
						used[board[i][j]] = true;
					}	
				}
			}
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int board[9][9];
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				scanf("%d", &board[i][j]);
			}
		}
		printf("Case %d: %s\n", a0, (correct(board) ? "CORRECT" : "INCORRECT"));
	}
	return 0;
}
