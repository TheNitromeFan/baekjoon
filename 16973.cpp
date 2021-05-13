#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1001

using namespace std;

int bfs(int map[][MAX], int n, int m, int sx, int sy, int fx, int fy){
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
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
		if(x == fx && y == fy){
			return dist[x][y];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] == 0 && dist[nx][ny] == -1){
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
	int n, m;
	cin >> n >> m;
	int board[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> board[i][j];
		}
	}
	int h, w, sr, sc, fr, fc;
	cin >> h >> w >> sr >> sc >> fr >> fc;
	int psum[MAX][MAX] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			psum[i][j] = board[i][j] + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
			// cout << psum[i][j] << ' ';
		}
		// cout << '\n';
	}
	int map[MAX][MAX] = {};
	for(int i = 1; i <= n - h + 1; ++i){
		for(int j = 1; j <= m - w + 1; ++j){
			map[i][j] = psum[i + h - 1][j + w - 1] - psum[i + h - 1][j - 1] - psum[i - 1][j + w - 1] + psum[i - 1][j - 1];
			// cout << map[i][j] << ' ';
		}
		// cout << '\n';
	}
	cout << bfs(map, n - h + 1, m - w + 1, sr, sc, fr, fc);
	return 0;
}
