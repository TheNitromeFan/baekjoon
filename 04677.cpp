#include <cstdio>
#define MAX 100

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(char map[][MAX], bool visited[][MAX], int m, int n, int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < m && ny >= 0 && ny < n && map[nx][ny] == '@' && !visited[nx][ny]){
			dfs(map, visited, m, n, nx, ny);
		}
	}
}

int main(){
	while(true){
		int m, n;
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0){
			break;
		}
		char land[MAX][MAX];
		for(int i = 0; i < m; ++i){
			scanf("%s", land[i]);
		}
		bool visited[MAX][MAX] = {};
		int depts = 0;
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(land[i][j] == '@' && !visited[i][j]){
					++depts;
					dfs(land, visited, m, n, i, j);
				}
			}
		}
		printf("%d\n", depts);
	}
	return 0;
}
