#include <cstdio>

using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int map[][250], int r, int c, int x, int y){
	map[x][y] = 0;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == 1){
			dfs(map, r, c, nx, ny);
		}
	}
}

int main(){
	int m, n;
	scanf("%d %d", &n, &m);
	int banner[250][250];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &banner[i][j]);
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(banner[i][j]){
				dfs(banner, n, m, i, j);
				++cnt;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
