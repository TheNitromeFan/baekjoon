#include <cstdio>
#define MAX 800

int pasture(char map[][MAX], bool visited[][MAX], int h, int w, int x, int y, int dx[8], int dy[8]){
	visited[x][y] = true;
	int ret = 1;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] == '.' && !visited[nx][ny]){
			ret += pasture(map, visited, h, w, nx, ny, dx, dy);
		}
	}
	return ret;
}

int main(){
	int w, h;
	scanf("%d %d", &w, &h);
	char map[MAX][MAX];
	for(int i = 0; i < h; ++i){
		scanf("%s", map[i]);
	}
	bool visited[MAX][MAX] = {};
	int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
	int ans = 0;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(map[i][j] == '.' && !visited[i][j]){
				int cmp = pasture(map, visited, h, w, i, j, dx, dy);
				if(ans < cmp){
					ans = cmp;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
