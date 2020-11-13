#include <cstdio>
#include <queue>
#define MAX_LENGTH (50 + 1)
#define MAX_HEIGHT 9

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(char map[][MAX_LENGTH], bool visited[][MAX_LENGTH], int n, int m, int sx, int sy){
	int ret = 0;
	std::queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	int h = map[sx][sy];
	bool spill = false;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		++ret;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m){
				spill = true;
				continue;
			}else if(map[nx][ny] > h || visited[nx][ny]){
				continue;
			}
			q.push(nx);
			q.push(ny);
			visited[nx][ny] = true;
		}
	}
	return spill ? 0 : ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX_LENGTH][MAX_LENGTH];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int ans = 0;
	for(int h = '0' + 1; h <= '0' + MAX_HEIGHT; ++h){
		bool visited[MAX_LENGTH][MAX_LENGTH] = {};
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(map[i][j] == h && !visited[i][j]){
					ans += bfs(map, visited, n, m, i, j);
				}
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(map[i][j] == h){
					++map[i][j];
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
