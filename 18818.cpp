#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 101

using namespace std;

int turns(char maze[][MAX], int n){
	queue<int> q;
	int visited[MAX][MAX];
	memset(visited, -1, sizeof(visited));
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	q.push(0);
	q.push(0);
	visited[0][0] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == n - 1 && y == n - 1){
			return visited[n - 1][n - 1];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x, ny = y;
			while(true){
				nx += dx[i];
				ny += dy[i];
				if(!(nx >= 0 && nx < n && ny >= 0 && ny < n && maze[nx][ny] == '.')){
					break;
				}
				if(visited[nx][ny] == -1){
					q.push(nx);
					q.push(ny);
					visited[nx][ny] = visited[x][y] + 1;
				}
			}
		}
	}
	return -1;
}

int main(){
	int n;
	scanf("%d", &n);
	char maze[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", maze[i]);
	}
	printf("%d", turns(maze, n));
	return 0;
}
