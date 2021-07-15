#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1500
#define OFFSET 750

using namespace std;

int bfs(bool map[][MAX], int destx, int desty){
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	q.push(OFFSET);
	q.push(OFFSET);
	dist[OFFSET][OFFSET] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == destx && y == desty){
			return dist[x][y];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && !map[nx][ny] && dist[nx][ny] == -1){
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
	int x, y, n;
	cin >> x >> y >> n;
	bool map[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		map[a + OFFSET][b + OFFSET] = true;
	}
	cout << bfs(map, x + OFFSET, y + OFFSET) << '\n';
	return 0;
}
