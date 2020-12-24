#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1000

using namespace std;

void traverse(int map[][MAX], int dist[][MAX], int n, int m, int sx, int sy){
	queue<int> q;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
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
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 1 && dist[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int map[MAX][MAX];
	int startx = -1, starty = -1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> map[i][j];
			if(map[i][j] == 2){
				startx = i;
				starty = j;
			}
		}
	}
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	traverse(map, dist, n, m, startx, starty);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << (map[i][j] ? dist[i][j] : 0) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
