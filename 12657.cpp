#include <cstdio>

char mark(int land[][100], char basin[][101], int r, int c, int x, int y, char &marker){
	if(basin[x][y] != 0){
		return basin[x][y];
	}
	int dx[5] = {0, -1, 0, 0, 1};
	int dy[5] = {0, 0, -1, 1, 0};
	int dir = 0;
	int minHeight = land[x][y];
	for(int i = 1; i <= 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && land[nx][ny] < minHeight){
			minHeight = land[nx][ny];
			dir = i;
		}
	}
	if(dir == 0){
		basin[x][y] = marker;
		++marker;
		return basin[x][y];
	}else{
		basin[x][y] = mark(land, basin, r, c, x + dx[dir], y + dy[dir], marker);
		return basin[x][y];
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int h, w;
		scanf("%d %d", &h, &w);
		int land[100][100];
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				scanf("%d", &land[i][j]);
			}
		}
		char basin[101][101] = {};
		char marker = 'a';
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				mark(land, basin, h, w, i, j, marker);
			}
		}
		printf("Case #%d:\n", a0);
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				printf("%c ", basin[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
