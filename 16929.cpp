#include <cstdio>
#include <cstring>
#define MAX 51

bool cycle(char board[][MAX], int visited[][MAX], int dx[4], int dy[4], int n, int m, int x, int y, char c, int steps){
	if(visited[x][y] != -1 && steps - visited[x][y] >= 4){
		return true;
	}else if(visited[x][y] != -1){
		return false;
	}
	visited[x][y] = steps;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == c
		&& cycle(board, visited, dx, dy, n, m, nx, ny, c, steps + 1)){
			return true;
		}
	}
	visited[x][y] = -1;
	return false;
}

bool has_cycle(char board[][MAX], int n, int m){
	int visited[MAX][MAX];
	memset(visited, -1, sizeof(visited));
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {-1, 0, 1, 0};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(cycle(board, visited, dx, dy, n, m, i, j, board[i][j], 0)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char board[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	printf("%s", has_cycle(board, n, m) ? "Yes" : "No");
	return 0;
}
