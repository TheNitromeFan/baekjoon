#include <cstdio>
#define MAX 500

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int paper[][MAX], bool visited[][MAX], int n, int m, int x, int y, int &cnt){
	++cnt;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && paper[nx][ny] && !visited[nx][ny]){
			visited[nx][ny] = true;
			dfs(paper, visited, n, m, nx, ny, cnt);
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int paper[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &paper[i][j]);
		}
	}
	bool visited[MAX][MAX] = {};
	int comp = 0, max = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(paper[i][j] && !visited[i][j]){
				++comp;
				int cnt = 0;
				visited[i][j] = true;
				dfs(paper, visited, n, m, i, j, cnt);
				if(max < cnt){
					max = cnt;
				}
			}
		}
	}
	printf("%d\n%d", comp, max);
	return 0;
}
