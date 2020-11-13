#include <cstdio>
#include <queue>
#define MAX (100 + 1)

using namespace std;

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

int bfs(int map[][MAX], int n, int m, int startx, int starty, int startdir, int endx, int endy, int enddir){
	queue<int> q;
	int visited[MAX][MAX][5] = {};
	q.push(startx);
	q.push(starty);
	q.push(startdir);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int dir = q.front();
		q.pop();
		// printf("%d %d %d %d\n", x, y, dir, visited[x][y][dir]);
		if(x == endx && y == endy && dir == enddir){
			return visited[x][y][dir];
		}
		for(int k = 1; k <= 3; ++k){
			int nx = x + dx[dir] * k, ny = y + dy[dir] * k;
			if(nx <= 0 || nx > n || ny <= 0 || ny > m || map[nx][ny] == 1){
				break;
			}
			if(!(nx == startx && ny == starty && dir == startdir) && visited[nx][ny][dir] == 0){
				q.push(nx);
				q.push(ny);
				q.push(dir);
				visited[nx][ny][dir] = visited[x][y][dir] + 1;
			}
		}
		for(int k = 0; k <= 2; ++k){
			int ndir = (dir + k) % 4 + 1;
			if((dir + ndir) % 4 == 3){
				continue;
			}
			if(!(x == startx && y == starty && ndir == startdir) && visited[x][y][ndir] == 0){
				q.push(x);
				q.push(y);
				q.push(ndir);
				visited[x][y][ndir] = visited[x][y][dir] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int map[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int startx, starty, startdir, endx, endy, enddir;
	scanf("%d %d %d %d %d %d", &startx, &starty, &startdir, &endx, &endy, &enddir);
	printf("%d", bfs(map, n, m, startx, starty, startdir, endx, endy, enddir));
	return 0;
}
