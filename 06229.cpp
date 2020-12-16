#include <iostream>
#include <queue>
#include <cstring>
#define MAX 30

using namespace std;

int jumps(int pond[][MAX], int m, int n, int m1, int m2, int sx, int sy){
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	int dx[8] = {m1, m1, -m1, -m1, m2, m2, -m2, -m2};
	int dy[8] = {m2, -m2, m2, -m2, m1, -m1, m1, -m1};
	q.push(sx);
	q.push(sy);
	dist[sx][sy] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(pond[x][y] == 4){
			return dist[x][y];
		}
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n && pond[nx][ny] != 0 && pond[nx][ny] != 2 && dist[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, m1, m2;
	cin >> m >> n >> m1 >> m2;
	int pond[MAX][MAX];
	int sx = -1, sy = -1;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> pond[i][j];
			if(pond[i][j] == 3){
				sx = i;
				sy = j;
			}
		}
	}
	cout << jumps(pond, m, n, m1, m2, sx, sy);
	return 0;
}
