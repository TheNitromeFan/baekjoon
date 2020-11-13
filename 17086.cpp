#include <cstdio>
#include <queue>
#define MAX 50

using namespace std;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int bfs(queue<int> &q, int map[][MAX], int n, int m){
	int dist[MAX][MAX] = {};
	int ret = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		ret = dist[x][y];
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m
			&& !map[nx][ny] && (dist[nx][ny] == 0 || dist[nx][ny] > dist[x][y] + 1)){
				dist[nx][ny] = dist[x][y] + 1;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int shark[MAX][MAX];
	queue<int> q;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &shark[i][j]);
			if(shark[i][j]){
				q.push(i);
				q.push(j);
			}
		}
	}
	printf("%d", bfs(q, shark, n, m));
	return 0;
}
