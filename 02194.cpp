#include <cstdio>
#include <cstring>
#include <queue>
#define MAX (500 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool can_move(bool board[][MAX], int n, int m, int a, int b, int x, int y, int movex, int movey){
	if(x + movex <= 0 || x + a - 1 + movex > n || y + movey <= 0 || y + b - 1 + movey > m){
		return false;
	}
	if(movex == 1){
		for(int j = y; j < y + b; ++j){
			if(!board[x + a][j]){
				return false;
			}
		}
	}else if(movex == -1){
		for(int j = y; j < y + b; ++j){
			if(!board[x - 1][j]){
				return false;
			}
		}
	}else if(movey == 1){
		for(int i = x; i < x + a; ++i){
			if(!board[i][y + b]){
				return false;
			}
		}
	}else if(movey == -1){
		for(int i = x; i < x + a; ++i){
			if(!board[i][y - 1]){
				return false;
			}
		}
	}
	return true;
}

int bfs(bool board[][MAX], int n, int m, int a, int b, int startx, int starty, int endx, int endy){
	std::queue<int> q;
	int visited[MAX][MAX] = {};
	q.push(startx);
	q.push(starty);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == endx && y == endy){
			return visited[x][y];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(can_move(board, n, m, a, b, x, y, dx[i], dy[i]) && !(nx == startx && ny == starty) && visited[nx][ny] == 0){
				visited[nx][ny] = visited[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	return -1;
}

int main(){
	int n, m, a, b, k;
	scanf("%d %d %d %d %d", &n, &m, &a, &b, &k);
	bool board[MAX][MAX];
	memset(board, true, sizeof(board));
	for(int i = 0; i < k; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		board[x][y] = false;
	}
	int startx, starty, endx, endy;
	scanf("%d %d %d %d", &startx, &starty, &endx, &endy);
	printf("%d", bfs(board, n, m, a, b, startx, starty, endx, endy));
	return 0;
}
