#include <cstdio>
#include <cstring>
#define MAX (1000 + 1)

int qx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int qy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int kx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int ky[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void mark_unsafe(int board[][MAX], bool safe[][MAX], int n, int m, int x, int y){
	int piece = board[x][y];
	switch(piece){
		case 1:
			for(int idx = 0; idx < 8; ++idx){
				int nx = x + qx[idx], ny = y + qy[idx];
				while(nx > 0 && nx <= n && ny > 0 && ny <= m && board[nx][ny] == 0){
					safe[nx][ny] = false;
					nx += qx[idx];
					ny += qy[idx];
				}
			}
			break;
		case 2:
			for(int idx = 0; idx < 8; ++idx){
				int nx = x + kx[idx], ny = y + ky[idx];
				if(nx > 0 && nx <= n && ny > 0 && ny <= m && board[nx][ny] == 0){
					safe[nx][ny] = false;
				}
			}
			break;
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	static int board[MAX][MAX] = {};
	static bool safe[MAX][MAX];
	memset(safe, true, sizeof(safe));
	for(int i = 1; i <= 3; ++i){
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; ++j){
			int r, c;
			scanf("%d %d", &r, &c);
			board[r][c] = i;
		}
	}
	for(int x = 1; x <= n; ++x){
		for(int y = 1; y <= m; ++y){
			if(board[x][y] == 1 || board[x][y] == 2){
				mark_unsafe(board, safe, n, m, x, y);
			}
		}
	}
	int ans = 0;
	for(int x = 1; x <= n; ++x){
		for(int y = 1; y <= m; ++y){
			if(board[x][y] == 0 && safe[x][y]){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
