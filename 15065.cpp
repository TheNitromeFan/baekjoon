#include <cstdio>
#define MAX 50

int row_ones(int a[][MAX], int c, int row){
	int ret = 0;
	for(int i = 0; i < c; ++i){
		if(a[row][i]){
			++ret;
		}
	}
	return ret;
}

int max_row_ones(int a[][MAX], int b[][MAX], int r, int c1, int c2){
	int ret = 0;
	for(int i = 0; i < r; ++i){
		int cmp = row_ones(a, c1, i) + row_ones(b, c2, i);
		if(ret < cmp){
			ret = cmp;
		}
	}
	return ret;
}

bool all_ones(int d[][MAX], int r, int c){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(!d[i][j]){
				return false;
			}
		}
	}
	return true;
}

bool mesh(int a[][MAX], int b[][MAX], int r, int c1, int c2){
	int columns = max_row_ones(a, b, r, c1, c2);
	int d[MAX][MAX] = {};
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c1; ++j){
			d[i][j] ^= a[i][j];
		}
		for(int j = columns - c2; j < columns; ++j){
			d[i][j] ^= b[i][j - columns + c2];
		}
	}
	return all_ones(d, r, columns);
}

int main(){
	int r, c1, c2;
	scanf("%d %d %d", &r, &c1, &c2);
	int a[MAX][MAX], b[MAX][MAX];
	char line[MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", line);
		for(int j = 0; j < c1; ++j){
			a[i][j] = line[j] - '0';
		}
	}
	for(int i = 0; i < r; ++i){
		scanf("%s", line);
		for(int j = 0; j < c2; ++j){
			b[i][j] = line[j] - '0';
		}
	}
	printf("%s", mesh(a, b, r, c1, c2) ? "Yes" : "No");
	return 0;
}
