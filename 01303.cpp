#include <cstdio>
#define MAX (100 + 1)

void dfs(char map[][MAX], bool visited[][MAX], int n, int m, int x, int y, int &ans){
	if(visited[x][y]){
		return;
	}
	visited[x][y] = true;
	++ans;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < m && ny >= 0 && ny < n && map[x][y] == map[nx][ny]){
			dfs(map, visited, n, m, nx, ny, ans);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	for(int i = 0; i < m; ++i){
		scanf("%s", map[i]);
	}
	bool visited[MAX][MAX] = {};
	int w = 0, b = 0, connected;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			connected = 0;
			if(!visited[i][j]){
				dfs(map, visited, n, m, i, j, connected);
			}
			if(map[i][j] == 'W'){
				w += connected * connected;
			}else{
				b += connected * connected;
			}
		}
	}
	printf("%d %d", w, b);
	return 0;
}
