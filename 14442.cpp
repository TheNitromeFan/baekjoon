#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 1001

using namespace std;

int bfs(char map[][MAX], int n, int m, int k){
	int dist[MAX][MAX][11];
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	bool visited[MAX][MAX][11] = {};
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	dist[0][0][0] = 1;
	q.push(0);
	q.push(0);
	q.push(0);
	visited[0][0][0] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int w = q.front();
		q.pop();
		if(x == n - 1 && y == m - 1){
			return dist[x][y][w];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
				continue;
			}
			if(map[nx][ny] == '0' && !visited[nx][ny][w]){
				dist[nx][ny][w] = dist[x][y][w] + 1;
				q.push(nx);
				q.push(ny);
				q.push(w);
				visited[nx][ny][w] = true;
			}else if(map[nx][ny] == '1' && w + 1 <= k && !visited[nx][ny][w + 1]){
				dist[nx][ny][w + 1] = dist[x][y][w] + 1;
				q.push(nx);
				q.push(ny);
				q.push(w + 1);
				visited[nx][ny][w + 1] = true;
			}
		}
	}
	return -1;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	printf("%d", bfs(map, n, m, k));
	return 0;
}
