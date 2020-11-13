#include <cstdio>
#include <queue>
#define MAX (1000 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs(char maze[][MAX], int n, int m, int startx, int starty, int endx, int endy){
	std::queue<int> q;
	bool visited[MAX][MAX] = {};
	q.push(startx);
	q.push(starty);
	visited[startx][starty] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == endx && y == endy){
			return true;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
			maze[nx][ny] == maze[startx][starty] && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return false;
}

int main(){
	int p;
	scanf("%d", &p);
	for(int a0 = 0; a0 < p; ++a0){
		int l, w, a, b, c, d;
		scanf("%d %d %d %d %d %d", &l, &w, &a, &b, &c, &d);
		char maze[MAX][MAX];
		for(int i = 0; i < w; ++i){
			scanf("%s", maze[i]);
		}
		printf("%s\n", bfs(maze, w, l, w - b, a - 1, w - d, c - 1) ? "YES" : "NO");
	}
	return 0;
}
