#include <cstdio>
#define MAX (1000 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(char map[][MAX], bool visited[][MAX], int n, int m, int x, int y, char a, char b){
	if(visited[x][y]){
		return;
	}
	visited[x][y] = true;
	map[x][y] = b;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == a){
			dfs(map, visited, n, m, nx, ny, a, b);
		}
	}
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char image[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", image[i]);
	}
	int x, y, k;
	scanf("%d %d %d", &x, &y, &k);
	bool visited[MAX][MAX] = {};
	dfs(image, visited, r, c, x, y, image[x][y], k + '0');
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%c", image[i][j]);
		}
		printf("\n");
	}
	return 0;
}
