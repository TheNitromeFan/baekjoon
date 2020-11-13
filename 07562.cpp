#include <cstdio>
#include <queue>
#define MAX 300

using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int sz, int startx, int starty, int endx, int endy){
	queue<int> q;
	int board[MAX][MAX] = {};
	q.push(startx);
	q.push(starty);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == endx && y == endy){
			return board[x][y];
		}
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < sz && ny >= 0 && ny < sz && !(nx == startx && ny == starty) && board[nx][ny] == 0){
				board[nx][ny] = board[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	return -1;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int scenario = 0; scenario < n; ++scenario){
		int len;
		scanf("%d", &len);
		int startx, starty, endx, endy;
		scanf("%d %d\n%d %d", &startx, &starty, &endx, &endy);
		printf("%d\n", bfs(len, startx, starty, endx, endy));
	}
	return 0;
}
