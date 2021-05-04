#include <cstdio>
#define MAX 16

bool cross(char board[][MAX], int n, int m, int x1, int y1, int r1, int x2, int y2, int r2){
	bool covered[MAX][MAX] = {};
	if(!(board[x1][y1] == '#' && board[x2][y2] == '#') || (x1 == x2 && y1 == y2)){
		return false;
	}
	covered[x1][y1] = true;
	covered[x2][y2] = true;
	for(int i = 1; i <= r1; ++i){
		if(!(x1 - i >= 0 && x1 + i < n && y1 - i >= 0 && y1 + i < m
		&& board[x1 - i][y1] == '#' && board[x1 + i][y1] == '#' && board[x1][y1 - i] == '#' && board[x1][y1 + i] == '#'
		&& !covered[x1 - i][y1] && !covered[x1 + i][y1] && !covered[x1][y1 - i] && !covered[x1][y1 + i])){
			return false;
		}
		covered[x1 - i][y1] = true;
		covered[x1 + i][y1] = true;
		covered[x1][y1 - i] = true;
		covered[x1][y1 + i] = true;
	}
	for(int j = 1; j <= r2; ++j){
		if(!(x2 - j >= 0 && x2 + j < n && y2 - j >= 0 && y2 + j < m
		&& board[x2 - j][y2] == '#' && board[x2 + j][y2] == '#' && board[x2][y2 - j] == '#' && board[x2][y2 + j] == '#'
		&& !covered[x2 - j][y2] && !covered[x2 + j][y2] && !covered[x2][y2 - j] && !covered[x2][y2 + j])){
			return false;
		}
		covered[x2 - j][y2] = true;
		covered[x2 + j][y2] = true;
		covered[x2][y2 - j] = true;
		covered[x2][y2 + j] = true;
	}
	return true;
}

int main(){
	char board[MAX][MAX];
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	int ans = 0;
	for(int x1 = 0; x1 < n; ++x1){
		for(int y1 = 0; y1 < m; ++y1){
			for(int x2 = 0; x2 < n; ++x2){
				for(int y2 = 0; y2 < m; ++y2){
					for(int r1 = 0; r1 < MAX; ++r1){
						for(int r2 = 0; r2 < MAX; ++r2){
							if(cross(board, n, m, x1, y1, r1, x2, y2, r2) && ans < (4 * r1 + 1) * (4 * r2 + 1)){
								ans = (4 * r1 + 1) * (4 * r2 + 1);
							}
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
