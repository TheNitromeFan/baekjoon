#include <cstdio>
#include <cstring>
#define MAX 100

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool no_cheese(int map[][MAX], int n, int m){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] == 1){
				return false;
			}
		}
	}
	return true;
}

void visit(int map[][MAX], bool marked[][MAX], int n, int m, int x, int y){
	marked[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0 && !marked[nx][ny]){
			visit(map, marked, n, m, nx, ny);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int time = 0;
	while(!no_cheese(map, n, m)){
		++time;
		bool visited[MAX][MAX] = {};
		for(int j = 0; j < m; ++j){
			if(map[0][j] == 0 && !visited[0][j]){
				visit(map, visited, n, m, 0, j);
			}
			if(map[n - 1][j] == 0 && !visited[n - 1][j]){
				visit(map, visited, n, m, n - 1, j);
			}
		}
		for(int i = 0; i < n; ++i){
			if(map[i][0] == 0 && !visited[i][0]){
				visit(map, visited, n, m, i, 0);
			}
			if(map[i][m - 1] == 0 && !visited[i][m - 1]){
				visit(map, visited, n, m, i, m - 1);
			}
		}
		int cnt[MAX][MAX] = {};
		for(int x = 0; x < n; ++x){
			for(int y = 0; y < m; ++y){
				if(map[x][y] == 1){
					for(int i = 0; i < 4; ++i){
						int nx = x + dx[i], ny = y + dy[i];
						if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny]){
							++cnt[x][y];
						}
					}
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(map[i][j] == 1 && cnt[i][j] >= 2){
					map[i][j] = 0;
				}
			}
		}
	}
	printf("%d", time);
	return 0;
}
