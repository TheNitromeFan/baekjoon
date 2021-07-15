#include <cstdio>
#define MAX 22

void dfs(char map[][MAX], bool visited[][MAX], int dx[4], int dy[4], int n, int m, int x, int y, int &cnt){
	visited[x][y] = true;
	++cnt;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == '.' && !visited[nx][ny]){
			dfs(map, visited, dx, dy, n, m, nx, ny, cnt);
		}
	}
}

int main(){
	while(true){
		int w, h;
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0){
			break;
		}
		char map[MAX][MAX];
		int sx = -1, sy = -1;
		for(int i = 0; i < h; ++i){
			scanf("%s", map[i]);
			for(int j = 0; j < w; ++j){
				if(map[i][j] == '@'){
					sx = i;
					sy = j;
				}
			}
		}
		bool visited[MAX][MAX] = {};
		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		int cnt = 0;
		dfs(map, visited, dx, dy, h, w, sx, sy, cnt);
		printf("%d\n", cnt);
	}
	return 0;
}
