#include <cstdio>
#include <queue>
#define SIZE (8 + 1)

using namespace std;

bool moving_walls(char board[SIZE][SIZE]){
	queue<int> q;
	bool visited[SIZE][SIZE][SIZE * SIZE] = {};
	int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
	int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	q.push(SIZE - 2);
	q.push(0);
	q.push(0);
	visited[SIZE - 2][0][0] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int t = q.front();
		q.pop();
		if(x == 0 && y == SIZE - 2){
			return true;
		}
		if(x - t >= 0 && board[x - t][y] == '#'){
			continue;
		}
		for(int i = 0; i < 9; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < SIZE - 1 && ny >= 0 && ny < SIZE - 1
			&& !(nx - t >= 0 && board[nx - t][ny] == '#') && !visited[nx][ny][t + 1]){
				q.push(nx);
				q.push(ny);
				q.push(t + 1);
				visited[nx][ny][t + 1] = true;
			}
		}
	}
	return false;
}

int main(){
	char board[SIZE][SIZE];
	for(int i = 0; i < SIZE - 1; ++i){
		scanf("%s", board[i]);
	}
	printf("%d", moving_walls(board));
	return 0;
}
