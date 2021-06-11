#include <cstdio>
#include <queue>
#define MAX 501

using namespace std;

int bfs(int map[][MAX], int m, int n){
	int dist[MAX][MAX];
	queue<int> q;
	bool visited[MAX][MAX] = {};
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	dist[0][0] = 0;
	q.push(0);
	q.push(0);
	visited[0][0] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == m - 1 && y == n - 1){
			return dist[x][y];
		}
		int c = map[x][y];
		for(int i = 0; i < 4; ++i){
			int nx = x + c * dx[i];
			int ny = y + c * dy[i];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]){
				dist[nx][ny] = dist[x][y] + 1;
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int map[MAX][MAX];
	for(int i = 0; i < m; ++i){
		char line[MAX];
		scanf("%s", line);
		for(int j = 0; j < n; ++j){
			map[i][j] = line[j] - '0';
		}
	}
	int ans = bfs(map, m, n);
	if(ans != -1){
		printf("%d", ans);
	}else{
		printf("IMPOSSIBLE");
	}
	return 0;
}
