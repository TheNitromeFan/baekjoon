#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

void bfs(bool map[][MAX], bool visited[][MAX], int n, int m, int sx, int sy, int dx[4], int dy[4]){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int rgb[MAX][MAX][3];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> rgb[i][j][0] >> rgb[i][j][1] >> rgb[i][j][2];
		}
	}
	int t;
	cin >> t;
	bool screen[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(rgb[i][j][0] + rgb[i][j][1] + rgb[i][j][2] >= 3 * t){
				screen[i][j] = true;
			}
		}
	}
	bool visited[MAX][MAX] = {};
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(screen[i][j] && !visited[i][j]){
				bfs(screen, visited, n, m, i, j, dx, dy);
				++cnt;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
