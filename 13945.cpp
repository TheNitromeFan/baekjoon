#include <cstdio>
#define MAX 112

bool all_bricks_row(char windows[][MAX], int row, int c){
	for(int j = 0; j < c; ++j){
		if(windows[row][j] != '#'){
			return false;
		}
	}
	return true;
}

bool all_bricks_col(char windows[][MAX], int r, int col){
	for(int i = 0; i < r; ++i){
		if(windows[i][col] != '#'){
			return false;
		}
	}
	return true;
}

void count_rows(char windows[][MAX], int r, int c, int &rows, int &row_size){
	int bricks = 0;
	for(int i = 0; i < r; ++i){
		if(all_bricks_row(windows, i, c)){
			++bricks;
		}
	}
	rows = bricks - 1;
	row_size = (r - bricks) / rows;
}

void count_cols(char windows[][MAX], int r, int c, int &cols, int &col_size){
	int bricks = 0;
	for(int j = 0; j < c; ++j){
		if(all_bricks_col(windows, r, j)){
			++bricks;
		}
	}
	cols = bricks - 1;
	col_size = (c - bricks) / cols;
}

bool match1(char windows[][MAX], int row_size, int col_size, int x1, int y1, int x2, int y2){
	for(int i = 0; i < row_size; ++i){
		for(int j = 0; j < col_size; ++j){
			if(windows[x1 + i][y1 + j] != windows[x2 + i][y2 + j]){
				return false;
			}
		}
	}
	return true;
}

bool match2(char windows[][MAX], int row_size, int col_size, int x1, int y1, int x2, int y2){
	if(row_size != col_size){
		return false;
	}
	for(int i = 0; i < row_size; ++i){
		for(int j = 0; j < col_size; ++j){
			if(windows[x1 + j][y1 + row_size - 1 - i] != windows[x2 + i][y2 + j]){
				return false;
			}
		}
	}
	return true;
}

bool match3(char windows[][MAX], int row_size, int col_size, int x1, int y1, int x2, int y2){
	for(int i = 0; i < row_size; ++i){
		for(int j = 0; j < col_size; ++j){
			if(windows[x1 + row_size - 1 - i][y1 + col_size - 1 - j] != windows[x2 + i][y2 + j]){
				return false;
			}
		}
	}
	return true;
}

bool match4(char windows[][MAX], int row_size, int col_size, int x1, int y1, int x2, int y2){
	if(row_size != col_size){
		return false;
	}
	for(int i = 0; i < row_size; ++i){
		for(int j = 0; j < col_size; ++j){
			if(windows[x1 + col_size - 1 - j][y1 + i] != windows[x2 + i][y2 + j]){
				return false;
			}
		}
	}
	return true;
}

bool match(char windows[][MAX], int row_size, int col_size, int x1, int y1, int x2, int y2){
	return match1(windows, row_size, col_size, x1, y1, x2, y2)
	|| match2(windows, row_size, col_size, x1, y1, x2, y2)
	|| match3(windows, row_size, col_size, x1, y1, x2, y2)
	|| match4(windows, row_size, col_size, x1, y1, x2, y2);
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char windows[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", windows[i]);
	}
	int rows = -1, cols = -1, row_size = -1, col_size = -1;
	count_rows(windows, r, c, rows, row_size);
	count_cols(windows, r, c, cols, col_size);
	int window_count = 0;
	for(int n = 0; n < rows * cols; ++n){
		int x1 = 1 + n / cols * (row_size + 1);
		int y1 = 1 + n % cols * (col_size + 1);
		bool match_found = false;
		for(int m = 0; m < n; ++m){
			int x2 = 1 + m / cols * (row_size + 1);
			int y2 = 1 + m % cols * (col_size + 1);
			if(match(windows, row_size, col_size, x1, y1, x2, y2)){
				match_found = true;
				break;
			}
		}
		if(!match_found){
			++window_count;
		}
	}
	printf("%d", window_count);
	return 0;
}
