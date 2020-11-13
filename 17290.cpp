#include <cstdio>
#include <queue>
#define SIZE 10

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool safe(char map[][SIZE + 1], int x, int y){
	for(int i = 0; i < SIZE; ++i){
		if(map[i][y] == 'o'){
			return false;
		}
	}
	for(int j = 0; j < SIZE; ++j){
		if(map[x][j] == 'o'){
			return false;
		}
	}
	return true;
}

int bfs(char map[][SIZE + 1], int startx, int starty){
	std::queue<int> q;
	int visited[SIZE][SIZE] = {};
	q.push(startx);
	q.push(starty);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(safe(map, x, y)){
			return visited[x][y];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && map[nx][ny] == 'x' && !(nx == startx && ny == starty) && visited[nx][ny] == 0){
				visited[nx][ny] = visited[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	return -1;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[SIZE][SIZE + 1];
	for(int i = 0; i < SIZE; ++i){
		scanf("%s", map[i]);
	}
	printf("%d", bfs(map, r - 1, c - 1));
	return 0;
}
