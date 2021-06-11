#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 51

using std::max;

void dfs(char grid[][MAX], int colored[][MAX], int dx[6], int dy[6], int n, int x, int y, int c, int &ans){
	colored[x][y] = c;
	ans = max(ans, 1);
	for(int i = 0; i < 6; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 'X')){
			continue;
		}
		if(colored[nx][ny] == -1){
			dfs(grid, colored, dx, dy, n, nx, ny, 1 - c, ans);
			if(ans < 2){
				ans = 2;
			}
		}
		if(colored[nx][ny] == c){
			ans = 3;
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	char grid[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", grid[i]);
	}
	int dx[6] = {0, 1, 1, 0, -1, -1};
	int dy[6] = {1, 0, -1, -1, 0, 1};
	int colored[MAX][MAX];
	memset(colored, -1, sizeof(colored));
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(grid[i][j] == 'X' && colored[i][j] == -1){
				dfs(grid, colored, dx, dy, n, i, j, 0, ans);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
