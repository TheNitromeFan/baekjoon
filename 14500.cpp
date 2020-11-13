#include <cstdio>
#define MAX 500

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[MAX][MAX];
bool visited[MAX][MAX];

int tetromino(int n, int m, int x, int y, int cnt){
	if(cnt == 0){
		return 0;
	}
	visited[x][y] = true;
	int ret = 0;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
			int cmp = tetromino(n, m, nx, ny, cnt-1) + map[nx][ny];
			if(ret < cmp){
				ret = cmp;
			}
		}
	}
	visited[x][y] = false;
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 0, cmp;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cmp = tetromino(n, m, i, j, 4);
			if(ans < cmp){
				ans = cmp;
			}
		}
	}
	// T
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + 2 < m; ++j){
			cmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			if(ans < cmp){
				ans = cmp;
			}
			cmp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if(ans < cmp){
				ans = cmp;
			}
		}
	}
	for(int i = 0; i + 2 < n; ++i){
		for(int j = 0; j + 1 < m; ++j){
			cmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			if(ans < cmp){
				ans = cmp;
			}
			cmp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if(ans < cmp){
				ans = cmp;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
