#include <cstdio>

bool valid(char board[8][9]){
	int sum = 0;
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			if(board[i][j] == '*'){
				++sum;
				for(int k = i + 1; k < 8; ++k){
					if(board[k][j] == '*'){
						return false;
					}
				}
				for(int l = j + 1; l < 8; ++l){
					if(board[i][l] == '*'){
						return false;
					}
				}
				for(int k = i + 1, l = j + 1; k < 8 && l < 8; ++k, ++l){
					if(board[k][l] == '*'){
						return false;
					}
				}
				for(int k = i + 1, l = j - 1; k < 8 && l >= 0; ++k, --l){
					if(board[k][l] == '*'){
						return false;
					}
				}
			}
		}
	}
	return sum == 8;
}

int main(){
	char b[8][9];
	for(int i = 0; i < 8; ++i){
		scanf("%s", b[i]);
	}
	printf("%s", valid(b) ? "valid" : "invalid");
	return 0;
}
