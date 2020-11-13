#include <cstdio>
#define MAX (100 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(bool map[][MAX], bool visited[][MAX], int n, int m, int x, int y){
	if(visited[x][y]){
		return 0;
	}
	visited[x][y] = true;
	int ret = 1;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny]){
			ret += dfs(map, visited, n, m, nx, ny);
		}
	}
	return ret;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	bool water[MAX][MAX] = {};
	for(int i = 0; i < k; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		water[x][y] = true;
	}
	bool visited[MAX][MAX] = {};
	int ans = 0;
	for(int x = 1; x <= n; ++x){
		for(int y = 1; y <= m; ++y){
			if(water[x][y]){
				int cmp = dfs(water, visited, n, m, x, y);
				if(ans < cmp){
					ans = cmp;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
