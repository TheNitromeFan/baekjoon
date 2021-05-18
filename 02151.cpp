#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 52

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char map[MAX][MAX];
	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	int doors = 0;
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < n; ++j){
			if(map[i][j] == '#' && doors){
				x2 = i;
				y2 = j;
				++doors;
			}else if(map[i][j] == '#'){
				x1 = i;
				y1 = j;
				++doors;
			}
		}
	}
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	dist[x1][y1] = 0;
	for(int k = 0; k < 4; ++k){
		int nx = x1 + dx[k], ny = y1 + dy[k];
		while(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] != '*'){
			dist[nx][ny] = 0;
			if(map[nx][ny] == '#' || map[nx][ny] == '!'){
				q.push(nx);
				q.push(ny);
			}
			nx += dx[k];
			ny += dy[k];
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
		for(int k = 0; k < 4; ++k){
			int nx = x + dx[k], ny = y + dy[k];
			while(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] != '*'){
				if(dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + 1){
					dist[nx][ny] = dist[x][y] + 1;
					if(map[nx][ny] == '#' || map[nx][ny] == '!'){
						q.push(nx);
						q.push(ny);
					}
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}
	printf("%d", dist[x2][y2]);
	return 0;
}
