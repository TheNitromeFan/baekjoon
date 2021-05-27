#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int bfs(int map[MAX][MAX], bool visited[MAX][MAX], int n, int sx, int sy, int dx[4], int dy[4]){
	queue<int> q1, q2;
	bool visited1[MAX][MAX] = {};
	q1.push(sx);
	q1.push(sy);
	visited[sx][sy] = true;
	while(!q1.empty()){
		int x = q1.front();
		q1.pop();
		int y = q1.front();
		q1.pop();
		q2.push(x);
		q2.push(y);
		visited1[x][y] = true;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] && !visited[nx][ny]){
				q1.push(nx);
				q1.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	int dist[MAX][MAX] = {};
	while(!q2.empty()){
		int x = q2.front();
		q2.pop();
		int y = q2.front();
		q2.pop();
		if(map[x][y] && dist[x][y] != 0){
			return dist[x][y] - 1;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited1[nx][ny]){
				dist[nx][ny] = dist[x][y] + 1;
				q2.push(nx);
				q2.push(ny);
				visited1[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> map[i][j];
		}
	}
	bool visited[MAX][MAX] = {};
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int ans = MAX * MAX;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] && !visited[i][j]){
				int cmp = bfs(map, visited, n, i, j, dx, dy);
				if(ans > cmp){
					ans = cmp;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
