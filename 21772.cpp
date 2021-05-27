#include <cstdio>
#include <algorithm>
#define MAX 101

int sweet_potatoes(char map[][MAX], bool visited[][MAX], int r, int c, int x, int y, int t, int cur, int cnt, int dx[4], int dy[4]){
	if(t == cur){
		return cnt;
	}
	int ret = sweet_potatoes(map, visited, r, c, x, y, t, cur + 1, cnt, dx, dy);
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] != '#'){
			if(map[nx][ny] == 'S' && !visited[nx][ny]){
				visited[nx][ny] = true;
				++cnt;
				ret = std::max(ret, sweet_potatoes(map, visited, r, c, nx, ny, t, cur + 1, cnt, dx, dy));
				--cnt;
				visited[nx][ny] = false;
			}else{
				ret = std::max(ret, sweet_potatoes(map, visited, r, c, nx, ny, t, cur + 1, cnt, dx, dy));
			}
		}
	}
	return ret;
}

int main(){
	int r, c, t;
	scanf("%d %d %d", &r, &c, &t);
	char map[MAX][MAX];
	int xg = -1, yg = -1;
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < c; ++j){
			if(map[i][j] == 'G'){
				xg = i;
				yg = j;
			}
		}
	}
	bool visited[MAX][MAX] = {};
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	printf("%d", sweet_potatoes(map, visited, r, c, xg, yg, t, 0, 0, dx, dy));
	return 0;
}
