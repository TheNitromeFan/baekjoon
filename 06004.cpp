#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 160

using std::queue;

int knight(char map[][MAX], int x, int y, int hx, int hy, int kx, int ky){
	queue<int> q;
	int visited[MAX][MAX];
	memset(visited, -1, sizeof(visited));
	int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	q.push(kx);
	q.push(ky);
	visited[kx][ky] = 0;
	while(!q.empty()){
		int sx = q.front();
		q.pop();
		int sy = q.front();
		q.pop();
		if(sx == hx && sy == hy){
			return visited[hx][hy];
		}
		for(int i = 0; i < 8; ++i){
			int nx = sx + dx[i], ny = sy + dy[i];
			if(nx >= 0 && nx < x && ny >= 0 && ny < y && visited[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = visited[sx][sy] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	char map[MAX][MAX];
	int kx = -1, ky = -1, hx = -1, hy = -1;
	for(int i = 0; i < y; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < x; ++j){
			if(map[i][j] == 'K'){
				kx = j;
				ky = i;
			}else if(map[i][j] == 'H'){
				hx = j;
				hy = i;
			}
		}
	}
	printf("%d", knight(map, x, y, hx, hy, kx, ky));
	return 0;
}
