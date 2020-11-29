#include <cstdio>

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void visit(char text[][101], bool visited[][101], int n, int m, int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && text[nx][ny] == '*' && !visited[nx][ny]){
			visit(text, visited, n, m, nx, ny);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char text[101][101];
	for(int i = 0; i < n; ++i){
		scanf("%s", text[i]);
	}
	int cnt = 0;
	bool visited[101][101] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(text[i][j] == '*' && !visited[i][j]){
				++cnt;
				visit(text, visited, n, m, i, j);
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
