#include <cstdio>
#include <queue>

char maze[20][20];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int r, int c, int sx, int sy){
	int moves[20][20];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			moves[i][j] = -1;
		}
	}
	moves[sx][sy] = 0;
	std::queue<int> q;
	q.push(sx);
	q.push(sy);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && maze[nx][ny] != 'X' && moves[nx][ny] == -1){
				moves[nx][ny] = moves[x][y] + 1;
				if(maze[nx][ny] == 'G'){
					return moves[nx][ny];
				}
				q.push(nx);
				q.push(ny);
			}
		}
	}
	return -1;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int r, c;
		scanf("%d %d", &r, &c);
		int startx, starty, goalx, goaly;
		for(int i = 0; i < r; ++i){
			scanf("%s", maze[i]);
			for(int j = 0; j < c; ++j){
				if(maze[i][j] == 'S'){
					startx = i;
					starty = j;
				}
			}
		}
		int ans = bfs(r, c, startx, starty);
		if(ans == -1){
			printf("No Exit\n");
		}else{
			printf("Shortest Path: %d\n", ans);
		}
	}
	return 0;
}
