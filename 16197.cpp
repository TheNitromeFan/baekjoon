#include <cstdio>
#include <algorithm>
#define MAX 22

void tilt(char board[][MAX], int n, int m, int x1, int y1, int x2, int y2,
		int dx[4], int dy[4], int moves, int &ans){
	if(moves > 10){
		return;
	}
	for(int i = 0; i < 4; ++i){
		int nx1 = x1 + dx[i], ny1 = y1 + dy[i], nx2 = x2 + dx[i], ny2 = y2 + dy[i];
		if(!(nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m)
		&& !(nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m)){
			continue;
		}else if(!(nx1 >= 0 && nx1 < n && ny1 >= 0 && ny1 < m)
		|| !(nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m)){
			ans = std::min(ans, moves);
		}else{
			if(board[nx1][ny1] == '#'){
				nx1 = x1;
				ny1 = y1;
			}
			if(board[nx2][ny2] == '#'){
				nx2 = x2;
				ny2 = y2;
			}
			tilt(board, n, m, nx1, ny1, nx2, ny2, dx, dy, moves + 1, ans);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char board[MAX][MAX];
	int coins = 0, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
		for(int j = 0; j < m; ++j){
			if(board[i][j] == 'o' && coins){
				x2 = i;
				y2 = j;
				++coins;
			}else if(board[i][j] == 'o'){
				x1 = i;
				y1 = j;
				++coins;
			}
		}
	}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int ans = MAX;
	tilt(board, n, m, x1, y1, x2, y2, dx, dy, 1, ans);
	printf("%d", ans <= 10 ? ans : -1);
	return 0;
}
