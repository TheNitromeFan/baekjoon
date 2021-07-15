#include <cstdio>
#define MAX (4 + 1)

bool is_safe(char board[][MAX], int x, int y){
	for(int px = x - 1; px >= 0; --px){
		if(board[px][y] == 'X'){
			break;
		}
		if(board[px][y] == 'R'){
			return false;
		}
	}
	for(int py = y - 1; py >= 0; --py){
		if(board[x][py] == 'X'){
			break;
		}
		if(board[x][py] == 'R'){
			return false;
		}
	}
	return true;
}

void place_rooks(char board[][MAX], int n, int x, int y, int cnt, int &max){
	if(x == n){
		if(cnt > max){
			max = cnt;
		}
		return;
	}
	int nx = x, ny = y + 1;
	if(ny == n){
		++nx;
		ny = 0;
	}
	place_rooks(board, n, nx, ny, cnt, max);
	if(board[x][y] == '.' && is_safe(board, x, y)){
		board[x][y] = 'R';
		++cnt;
		place_rooks(board, n, nx, ny, cnt, max);
		--cnt;
		board[x][y] = '.';
	}
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		char board[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", board[i]);
		}
		int ans = 0;
		place_rooks(board, n, 0, 0, 0, ans);
		printf("%d\n", ans);
	}
	return 0;
}
