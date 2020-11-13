#include <cstdio>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void spread(int src[][50], int r, int c){
	int tmp[50][50] = {};
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			int amt = src[i][j] / 5;
			for(int k = 0; k < 4; ++k){
				int nx = i + dx[k], ny = j + dy[k];
				if(nx >= 0 && nx < r && ny >= 0 && ny < c && src[nx][ny] != -1){
					src[i][j] -= amt;
					tmp[nx][ny] += amt;
				}
			}
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			src[i][j] += tmp[i][j];
		}
	}
}

void cycle(int src[][50], int r, int c, int top, int bottom){
	for(int i = top-1; i > 0; --i){
		src[i][0] = src[i-1][0];
	}
	for(int j = 0; j < c-1; ++j){
		src[0][j] = src[0][j+1];
	}
	for(int i = 0; i < top; ++i){
		src[i][c-1] = src[i+1][c-1];
	}
	for(int j = c-1; j > 1; --j){
		src[top][j] = src[top][j-1];
	}
	src[top][1] = 0;
	for(int i = bottom+1; i < r-1; ++i){
		src[i][0] = src[i+1][0];
	}
	for(int j = 0; j < c-1; ++j){
		src[r-1][j] = src[r-1][j+1];
	}
	for(int i = r-1; i > bottom; --i){
		src[i][c-1] = src[i-1][c-1];
	}
	for(int j = c-1; j > 1; --j){
		src[bottom][j] = src[bottom][j-1];
	}
	src[bottom][1] = 0;
}

int main(){
	int r, c, t;
	scanf("%d %d %d", &r, &c, &t);
	int top = 0, bottom = 0;
	int map[50][50];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == -1 && top == 0){
				top = i;
				bottom = i+1;
			}
		}
	}
	for(int t0 = 0; t0 < t; ++t0){
		spread(map, r, c);
		cycle(map, r, c, top, bottom);
	}
	int ans = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] != -1){
				ans += map[i][j];
			}
		}
	}
	printf("%d", ans);
	return 0;
}
