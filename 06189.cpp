#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 101

using namespace std;

int munch(char grid[][MAX], int r, int c, int startx, int starty, int endx, int endy){
	queue<int> q;
	int visited[MAX][MAX];
	memset(visited, -1, sizeof(visited));
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	q.push(startx);
	q.push(starty);
	visited[startx][starty] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == endx && y == endy){
			return visited[endx][endy];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] != '*' && visited[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	return visited[endx][endy];
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char grid[MAX][MAX];
	int barnx = -1, barny = -1, cowx = -1, cowy = -1;
	for(int i = 0; i < r; ++i){
		scanf("%s", grid[i]);
		for(int j = 0; j < c; ++j){
			if(grid[i][j] == 'B'){
				barnx = i;
				barny = j;
			}else if(grid[i][j] == 'C'){
				cowx = i;
				cowy = j;
			}
		}
	}
	printf("%d", munch(grid, r, c, cowx, cowy, barnx, barny));
	return 0;
}
