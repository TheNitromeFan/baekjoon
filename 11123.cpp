#include <cstdio>
#define MAX (100 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(char field[][MAX], bool visited[][MAX], int n, int m, int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] == '#' && !visited[nx][ny]){
			dfs(field, visited, n, m, nx, ny);
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int r, c;
		scanf("%d %d", &r, &c);
		char field[MAX][MAX];
		for(int i = 0; i < r; ++i){
			scanf("%s", field[i]);
		}
		bool visited[MAX][MAX] = {};
		int cnt = 0;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				if(field[i][j] == '#' && !visited[i][j]){
					++cnt;
					dfs(field, visited, r, c, i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
