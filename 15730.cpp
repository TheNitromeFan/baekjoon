#include <cstdio>
#include <queue>
#define MAX_LENGTH (100 + 2)
#define MAX_HEIGHT 10000

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int map[][MAX_LENGTH], bool now[][MAX_LENGTH], int n, int m, int sx, int sy){
	std::queue<int> q;
	q.push(sx);
	q.push(sy);
	now[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || nx >= n + 2 || ny < 0 || ny >= m + 2){
				continue;
			}else if(now[nx][ny]){
				continue;
			}
			q.push(nx);
			q.push(ny);
			now[nx][ny] = true;
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int map[MAX_LENGTH][MAX_LENGTH];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int ans = 0;
	for(int h = 1; h <= MAX_HEIGHT; ++h){
		bool now[MAX_LENGTH][MAX_LENGTH] = {};
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(map[i][j] >= h){
					now[i + 1][j + 1] = true;
				}
			}
		}
		bfs(map, now, n, m, 0, 0);
		for(int i = 0; i <= n + 1; ++i){
			for(int j = 0; j <= m + 1; ++j){
				if(!now[i][j]){
					++ans;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
