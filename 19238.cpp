#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define MAX 21
#define MAXMAX (MAX * MAX)

using namespace std;

void get_distances(int map[][MAX], int n, int sx, int sy, int dx[4], int dy[4], int dist[][MAX]){
	queue<int> q;
	dist[sx][sy] = 0;
	q.push(sx);
	q.push(sy);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && map[nx][ny] == 0 && dist[nx][ny] == -1){
				dist[nx][ny] = dist[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
}

int taxi(int map[][MAX], int n, int x, int y,
		pair<int, int> pickup[MAXMAX], pair<int, int> dropoff[MAXMAX], int m,
		int dx[4], int dy[4], int fuel){
	bool rode[MAXMAX] = {};
	for(int a0 = 0; a0 < m; ++a0){
		int dist[MAX][MAX];
		memset(dist, -1, sizeof(dist));
		get_distances(map, n, x, y, dx, dy, dist);
		int next = -1, nextx = -1, nexty = -1, min_dist = 2 * MAXMAX;
		for(int i = 1; i <= m; ++i){
			if(rode[i]){
				continue;
			}
			int nx = pickup[i].first, ny = pickup[i].second;
			if(dist[nx][ny] == -1){
				return -1;
			}
			if(next == -1 || dist[nx][ny] < min_dist
			|| (dist[nx][ny] == min_dist && nx < nextx)
			|| (dist[nx][ny] == min_dist && nx == nextx && ny < nexty)){
				next = i;
				nextx = nx;
				nexty = ny;
				min_dist = dist[nx][ny];
			}
		}
		if(fuel < min_dist){
			return -1;
		}
		fuel -= min_dist;
		x = nextx;
		y = nexty;
		memset(dist, -1, sizeof(dist));
		get_distances(map, n, x, y, dx, dy, dist);
		nextx = dropoff[next].first;
		nexty = dropoff[next].second;
		if(fuel < dist[nextx][nexty]){
			return -1;
		}
		fuel += dist[nextx][nexty];
		x = nextx;
		y = nexty;
		rode[next] = true;
	}
	return fuel;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, fuel;
	cin >> n >> m >> fuel;
	int map[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> map[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	pair<int, int> pickup[MAXMAX], dropoff[MAXMAX];
	for(int k = 1; k <= m; ++k){
		cin >> pickup[k].first >> pickup[k].second >> dropoff[k].first >> dropoff[k].second;
	}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	cout << taxi(map, n, x, y, pickup, dropoff, m, dx, dy, fuel);
	return 0;
}
