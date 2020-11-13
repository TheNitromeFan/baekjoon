#include <cstdio>
#define MAX 500

int dp[MAX+1][MAX+1];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int map[][MAX+1], int size, int x, int y){
	if(dp[x][y]){
		return dp[x][y];
	}
	dp[x][y] = 1;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || nx > size || ny < 1 || ny > size || map[nx][ny] <= map[x][y]){
			continue;
		}
		int cmp = dfs(map, size, nx, ny) + 1;
		if(cmp > dp[x][y]){
			dp[x][y] = cmp;
		}
	}
	return dp[x][y];
}

int main(){
	int n;
	scanf("%d", &n);
	int map[MAX+1][MAX+1] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int tmp = dfs(map, n, i, j);
			if(tmp > ans){
				ans = tmp;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
