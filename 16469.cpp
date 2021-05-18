#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 105

using namespace std;

void bfs(char map[][MAX], int dist[][MAX], int r, int c, int sx, int sy, int dx[4], int dy[4]){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	dist[sx][sy] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == '0' && dist[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	int travel[3][MAX][MAX];
	memset(travel, -1, sizeof(travel));
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	for(int k = 0; k < 3; ++k){
		int xi, yi;
		scanf("%d %d", &xi, &yi);
		--xi;
		--yi;
		bfs(map, travel[k], r, c, xi, yi, dx, dy);
	}
	int min_meet = -1, cnt = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			// printf("%d %d %d    ", travel[0][i][j], travel[1][i][j], travel[2][i][j]);
			if(travel[0][i][j] == -1 || travel[1][i][j] == -1 || travel[2][i][j] == -1){
				continue;
			}
			int time = max(max(travel[0][i][j], travel[1][i][j]), travel[2][i][j]);
			if(min_meet == -1 || min_meet > time){
				min_meet = time;
				cnt = 1;
			}else if(min_meet == time){
				++cnt;
			}
		}
		// printf("\n");
	}
	if(min_meet != -1){
		printf("%d\n%d", min_meet, cnt);
	}else{
		printf("-1");
	}
	return 0;
}
