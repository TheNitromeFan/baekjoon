#include <cstdio>

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void visit(char dish[][101], bool visited[][101], int m, int n, int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < m && ny >= 0 && ny < n && dish[nx][ny] == '#' && !visited[nx][ny]){
			visit(dish, visited, m, n, nx, ny);
		}
	}
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	char dish[101][101];
	for(int i = 0; i < m; ++i){
		scanf("%s", dish[i]);
	}
	int cnt = 0;
	bool visited[101][101] = {};
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(dish[i][j] == '#' && !visited[i][j]){
				++cnt;
				visit(dish, visited, m, n, i, j);
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
