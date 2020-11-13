#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 50

char a[MAX][MAX];

int dp[MAX][MAX];

bool visited[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int n, int m, int x, int y){
	if(!(x >= 0 && x < n && y >= 0 && y < m) || a[x][y] == 'H'){
		return 0;
	}else if(visited[x][y]){
		printf("-1");
		exit(0);
	}else if(dp[x][y] != -1){
		return dp[x][y];
	}
	visited[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i] * (a[x][y] - '0'), ny = y + dy[i] * (a[x][y] - '0');
		int cmp = dfs(n, m, nx, ny);
		if(dp[x][y] < cmp + 1){
			dp[x][y] = cmp + 1;
		}
	}
	visited[x][y] = false;
	return dp[x][y];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%s", a[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", dfs(n, m, 0, 0));
	return 0;
}
