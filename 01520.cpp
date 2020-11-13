#include <cstdio>
#include <cstring>
#define MAX 500

int dp[MAX+1][MAX+1];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int map[][MAX+1], int n, int m, int x, int y){
	if(x == n && y == m){
		return 1;
	}
	if(dp[x][y] != -1){
		return dp[x][y];
	}
	dp[x][y] = 0;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] < map[x][y]){
			dp[x][y] += dfs(map, n, m, nx, ny);			
		}
	}
	return dp[x][y];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int map[MAX+1][MAX+1];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", dfs(map, n, m, 1, 1));
	return 0;
}
