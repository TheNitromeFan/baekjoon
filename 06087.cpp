#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 102

using namespace std;

int main(){
	int w, h;
	scanf("%d %d", &w, &h);
	char map[MAX][MAX];
	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	int cows = 0;
	for(int i = 0; i < h; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < w; ++j){
			if(map[i][j] == 'C' && cows){
				x2 = i;
				y2 = j;
				++cows;
			}else if(map[i][j] == 'C'){
				x1 = i;
				y1 = j;
				++cows;
			}
		}
	}
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	q.push(x1);
	q.push(y1);
	dist[x1][y1] = 0;
	for(int i = 0; i < 4; ++i){
		int nx = x1 + dx[i], ny = y1 + dy[i];
		while(nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] != '*'){
			q.push(nx);
			q.push(ny);
			dist[nx][ny] = 0;
			nx += dx[i];
			ny += dy[i];
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == x2 && y == y2){
			break;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			while(nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] != '*'){
				if(dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + 1){
					q.push(nx);
					q.push(ny);
					dist[nx][ny] = dist[x][y] + 1;
				}
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
	/*
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d", dist[x2][y2]);
	return 0;
}
