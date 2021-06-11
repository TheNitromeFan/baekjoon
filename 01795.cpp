#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 51
#define MAXVAL 1000000000

void bfs(int sum_dist[][MAX], int dx[8], int dy[8], int n, int m, int sx, int sy, int k){
	int dist[MAX][MAX];
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < m; ++y){
			dist[x][y] = MAXVAL;
		}
	}
	std::queue<int> q;
	bool visited[MAX][MAX] = {};
	dist[sx][sy] = 0;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
				dist[nx][ny] = dist[x][y] + 1;
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < m; ++y){
			if(sum_dist[x][y] == MAXVAL || dist[x][y] == MAXVAL){
				sum_dist[x][y] = MAXVAL;
			}else if(dist[x][y] % k == 0){
				sum_dist[x][y] += dist[x][y] / k;
			}else{
				sum_dist[x][y] += dist[x][y] / k + 1;
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	int dist[MAX][MAX] = {};
	int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
	int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < m; ++j){
			if(map[i][j] != '.'){
				bfs(dist, dx, dy, n, m, i, j, map[i][j] - '0');
			}
		}
	}
	int ans = MAXVAL;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(dist[i][j] < ans){
				ans = dist[i][j];
			}
		}
	}
	if(ans < MAXVAL){
		printf("%d", ans);
	}else{
		printf("-1");
	}
	return 0;
}
