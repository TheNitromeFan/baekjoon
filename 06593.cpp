#include <cstdio>
#include <queue>
#define MAX (30 + 1)

using namespace std;

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int bfs(char maze[][MAX][MAX], int ell, int r, int c, int startx, int starty, int startz){
	queue<int> q;
	int time[MAX][MAX][MAX] = {};
	q.push(startx);
	q.push(starty);
	q.push(startz);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int z = q.front();
		q.pop();
		if(maze[x][y][z] == 'E'){
			return time[x][y][z];
		}
		for(int i = 0; i < 6; ++i){
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if(nx >= 0 && nx < ell && ny >= 0 && ny < r && nz >= 0 && nz < c && !(nx == startx && ny == starty && nz == startz)
			&& time[nx][ny][nz] == 0 && maze[nx][ny][nz] != '#'){
				q.push(nx);
				q.push(ny);
				q.push(nz);
				time[nx][ny][nz] = time[x][y][z] + 1;
			}
		}
	}
	return -1;
}

int main(){
	while(true){
		int ell, r, c;
		scanf("%d %d %d", &ell, &r, &c);
		if(ell == 0 && r == 0 && c == 0){
			break;
		}
		char maze[MAX][MAX][MAX];
		int startx = 0, starty = 0, startz = 0;
		for(int i = 0; i < ell; ++i){
			for(int j = 0; j < r; ++j){
				scanf("%s", maze[i][j]);
				for(int k = 0; k < c; ++k){
					if(maze[i][j][k] == 'S'){
						startx = i;
						starty = j;
						startz = k;
					}
				}
			}
		}
		int ans = bfs(maze, ell, r, c, startx, starty, startz);
		if(ans == -1){
			printf("Trapped!\n");
		}else{
			printf("Escaped in %d minute(s).\n", ans);
		}
	}
	return 0;
}
