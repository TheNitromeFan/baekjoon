#include <cstdio>

bool ttt(char b[6][6], char x){
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 3; ++j){
			if(b[i][j] == x && b[i][j + 1] == x && b[i][j + 2] == x){
				return true;
			}
		}
	}
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 5; ++j){
			if(b[i][j] == x && b[i + 1][j] == x && b[i + 2][j] == x){
				return true;
			}
		}
	}
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(b[i][j] == x && b[i + 1][j + 1] == x && b[i + 2][j + 2] == x){
				return true;
			}
		}
	}
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(b[i + 2][j] == x && b[i + 1][j + 1] == x && b[i][j + 2] == x){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int a0 = 0; a0 < n; ++a0){
		char board[6][6];
		for(int i = 0; i < 5; ++i){
			scanf("%s", board[i]);
		}
		bool a = ttt(board, 'A'), b = ttt(board, 'B');
		if(a && !b){
			printf("A wins\n");
		}else if(!a && b){
			printf("B wins\n");
		}else{
			printf("draw\n");
		}
	}
	return 0;
}
