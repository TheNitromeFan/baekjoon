#include <cstdio>
#include <cstdlib>
#include <map>

char board[65][65];

bool all_same(int n, int startx, int starty){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(board[startx+i][starty+j] != board[startx][starty]){
				return false;
			}
		}
	}
	return true;
}

void compress(int n, int startx, int starty){
	if(all_same(n, startx, starty)){
		printf("%c", board[startx][starty]);
		return;
	}
	printf("(");
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j){
			compress(n/2, startx + i*n/2, starty + j*n/2);
		}
	}
	printf(")");
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	compress(n, 0, 0);
	return 0;
}
