#include <cstdio>
#include <queue>
#define MAX (1000 + 1)

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int maze[][MAX], int r, int c, int startx, int starty, int endx, int endy){
	queue<int> q;
	static int visited[MAX][MAX][2] = {};
	q.push(startx);
	q.push(starty);
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int z = q.front();
		q.pop();
		if(x == endx && y == endy){
			return visited[x][y][z];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i], nz;
			if(nx <= 0 || nx > r || ny <= 0 || ny > c){
				continue;
			}
			if(maze[nx][ny] == 0){
				nz = z;
			}else{
				nz = z + 1;
			}
			if(nz < 2 && !(nx == x && ny == y) && visited[nx][ny][nz] == 0){
				visited[nx][ny][nz] = visited[x][y][z] + 1;
				q.push(nx);
				q.push(ny);
				q.push(nz);
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int hx, hy, ex, ey;
	scanf("%d %d %d %d", &hx, &hy, &ex, &ey);
	static int maze[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &maze[i][j]);
		}
	}
	printf("%d", bfs(maze, n, m, hx, hy, ex, ey));
	return 0;
}
