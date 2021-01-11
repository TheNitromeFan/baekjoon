#include <cstdio>
#define MAX 513

void fill_board(char board[][MAX], int x, int y, unsigned val){
	for(int j = y; j < y + 8; ++j){
		if(val % 2 == 1){
			board[x][j] = 'B';
		}else{
			board[x][j] = 'W';
		}
		val /= 2;
	}
}

bool all_same(char board[][MAX], int n, int x, int y){
	for(int i = x; i < x + n; ++i){
		for(int j = y; j < y + n; ++j){
			if(board[i][j] != board[x][y]){
				return false;
			}
		}
	}
	return true;
}

void print_board(char board[][MAX], int n, int x, int y){
	if(all_same(board, n, x, y)){
		printf("%c", board[x][y]);
		return;
	}
	printf("Q");
	print_board(board, n / 2, x, y);
	print_board(board, n / 2, x, y + n / 2);
	print_board(board, n / 2, x + n / 2, y);
	print_board(board, n / 2, x + n / 2, y + n / 2);
}

int main(){
	int n;
	scanf("#define quadtree_width %d\n", &n);
	scanf("#define quadtree_height %d\n", &n);
	scanf("static char quadtree_bits[] = {\n");
	char board[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; j += 8){
			unsigned val;
			scanf("0x%x,", &val);
			fill_board(board, i, j, val);
		}
		scanf("\n");
	}
	scanf("};");
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d\n", n);
	print_board(board, n, 0, 0);
	return 0;
}
