#include <cstdio>
#include <queue>
#define MAX 100

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(char board[][MAX+1], int c, int r, int startx, int starty, int endx, int endy){
	queue<int> q;
	q.push(startx);
	q.push(starty);
	int dist[MAX+1][MAX+1];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			dist[i][j] = MAX * MAX;
		}
	}
	dist[startx][starty] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 0 && nx < r && ny >= 0 && ny < c)){
				continue;
			}
			if(board[nx][ny] == '0' && dist[nx][ny] > dist[x][y]){
				q.push(nx);
				q.push(ny);
				dist[nx][ny] = dist[x][y];
			}else if(board[nx][ny] == '1' && dist[nx][ny] > dist[x][y] + 1){
				q.push(nx);
				q.push(ny);
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	return dist[endx][endy];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX+1][MAX+1];
	for(int i = 0; i < m; ++i){
		scanf("%s", map[i]);
	}
	printf("%d", bfs(map, n, m, 0, 0, m-1, n-1));
	return 0;
}
