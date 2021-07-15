#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 51

using namespace std;

bool clear(char map[][MAX], int n, int x, int y){
	if(x == 0 || x == n - 1 || y == 0 || y == n - 1){
		return false;
	}
	for(int i = x - 1; i <= x + 1; ++i){
		for(int j = y - 1; j <= y + 1; ++j){
			if(map[i][j] == '1'){
				return false;
			}
		}
	}
	return true;
}

int bfs(char map[][MAX], int n, int bx, int by, int bdir, int ex, int ey, int edir){
	queue<int> q;
	int dist[MAX][MAX][2];
	memset(dist, -1, sizeof(dist));
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	q.push(bx);
	q.push(by);
	q.push(bdir);
	dist[bx][by][bdir] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int dir = q.front();
		q.pop();
		if(x == ex && y == ey && dir == edir){
			return dist[x][y][dir];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if((dir == 0 && nx - 1 >= 0 && nx + 1 < n && ny >= 0 && ny < n && map[nx - 1][ny] != '1' && map[nx][ny] != '1' && map[nx + 1][ny] != '1' && dist[nx][ny][dir] == -1)
			|| (dir == 1 && nx >= 0 && nx < n && ny - 1 >= 0 && ny + 1 < n && map[nx][ny - 1] != '1' && map[nx][ny] != '1' && map[nx][ny + 1] != '1' && dist[nx][ny][dir] == -1)){
				q.push(nx);
				q.push(ny);
				q.push(dir);
				dist[nx][ny][dir] = dist[x][y][dir] + 1;
			}
		}
		if(clear(map, n, x, y) && dist[x][y][!dir] == -1){
			q.push(x);
			q.push(y);
			q.push(!dir);
			dist[x][y][!dir] = dist[x][y][dir] + 1;
		}
	}
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int bx = -1, by = -1, bdir = -1, ex = -1, ey = -1, edir = -1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i - 1 >= 0 && i + 1 < n && map[i - 1][j] == 'B' && map[i][j] == 'B' && map[i + 1][j] == 'B'){
				bx = i;
				by = j;
				bdir = 0;
			}else if(j - 1 >= 0 && j + 1 < n && map[i][j - 1] == 'B' && map[i][j] == 'B' && map[i][j + 1] == 'B'){
				bx = i;
				by = j;
				bdir = 1;
			}else if(i - 1 >= 0 && i + 1 < n && map[i - 1][j] == 'E' && map[i][j] == 'E' && map[i + 1][j] == 'E'){
				ex = i;
				ey = j;
				edir = 0;
			}else if(j - 1 >= 0 && j + 1 < n && map[i][j - 1] == 'E' && map[i][j] == 'E' && map[i][j + 1] == 'E'){
				ex = i;
				ey = j;
				edir = 1;
			}
		}
	}
	printf("%d\n", bfs(map, n, bx, by, bdir, ex, ey, edir));
	return 0;
}
