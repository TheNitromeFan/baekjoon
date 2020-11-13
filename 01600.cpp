#include <cstdio>
#include <queue>
#define MAX 200

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int kx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int ky[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int map[][MAX], int n, int m, int k, int startx, int starty, int endx, int endy){
	std::queue<int> q;
	static int visited[MAX][MAX][31] = {};
	q.push(startx);
	q.push(starty);
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int knight = q.front();
		q.pop();
		if(x == endx && y == endy){
			return visited[x][y][knight];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !(nx == startx && ny == starty && knight == 0)
			&& map[nx][ny] == 0 && visited[nx][ny][knight] == 0){
				visited[nx][ny][knight] = visited[x][y][knight] + 1;
				q.push(nx);
				q.push(ny);
				q.push(knight);
			}
		}
		if(knight == k){
			continue;
		}
		for(int i = 0; i < 8; ++i){
			int nx = x + kx[i], ny = y + ky[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m
			&& map[nx][ny] == 0 && visited[nx][ny][knight + 1] == 0){
				visited[nx][ny][knight + 1] = visited[x][y][knight] + 1;
				q.push(nx);
				q.push(ny);
				q.push(knight + 1);
			}
		}
	}
	return -1;
}

int main(){
	int k, n, m;
	scanf("%d %d %d", &k, &m, &n);
	int map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", bfs(map, n, m, k, 0, 0, n - 1, m - 1));
	return 0;
}
