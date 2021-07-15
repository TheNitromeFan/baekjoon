#include <cstdio>
#define MAX 11

void copy(char src[][MAX], char dest[][MAX], int n, int m){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			dest[i][j] = src[i][j];
		}
	}
}

int mex(char board[][MAX], int n, int m, int pos){
	if(pos == n * m){
		return 0;
	}
	int x = pos / m, y = pos % m;
	if(board[x][y] == '#'){
		return mex(board, n, m, pos + 1);
	}
	char board1[MAX][MAX];
	copy(board, board1, n, m);
	bool checked[200] = {};
	board1[x][y] = '#';
	int m1 = mex(board1, n, m, pos + 1);
	checked[m1] = true;
	if(x + 1 < n && y + 1 < m && x % 2 == 0 && board1[x][y + 1] == '.' && board1[x + 1][y] == '.' && board1[x + 1][y + 1] == '.'){
		board1[x][y + 1] = '#';
		board1[x + 1][y] = '#';
		board1[x + 1][y + 1] = '#';
		int m2 = mex(board1, n, m, pos + 2);
		checked[m2] = true;
	}
	for(int k = 0; k < 200; ++k){
		if(!checked[k]){
			return k;
		}
	}
	return -1;
}

int main(){
	for(int a0 = 0; a0 < 3; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		char board[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", board[i]);
		}
		printf("%c\n", mex(board, n, m, 0) ? 'Y' : 'M');
	}
	return 0;
}
