#include <cstdio>

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

void visit(char grid[][51], bool visited[][51], int r, int c, int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] != 'W' && !visited[nx][ny]){
			visit(grid, visited, r, c, nx, ny);
		}
	}
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char grid[51][51];
	for(int i = 0; i < r; ++i){
		scanf("%s", grid[i]);
	}
	bool visited[51][51] = {};
	int islands = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(grid[i][j] == 'L' && !visited[i][j]){
				visit(grid, visited, r, c, i, j);
				++islands;
			}
		}
	}
	printf("%d", islands);
	return 0;
}
