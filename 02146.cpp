#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 100

using std::queue;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int map[][MAX], bool visited[][MAX], int sz, int x, int y, int number){
	map[x][y] = number;
	visited[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < sz && ny >= 0 && ny < sz && map[nx][ny] == 1 && !visited[nx][ny]){
			dfs(map, visited, sz, nx, ny, number);
		}
	}
}

int bfs(int map[][MAX], bool visited[][MAX], int sz, int number){
	queue<int> q;
	int steps[MAX][MAX] = {};
	for(int x = 0; x < sz; ++x){
		for(int y = 0; y < sz; ++y){
			if(map[x][y] == number){
				q.push(x);
				q.push(y);
				visited[x][y] = true;
			}
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < sz && ny >= 0 && ny < sz && !visited[nx][ny]){
				if(map[nx][ny] != 0 && map[nx][ny] != number){
					return steps[x][y];
				}
				steps[nx][ny] = steps[x][y] + 1;
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	bool visited[MAX][MAX] = {};
	int number = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] == 1 && !visited[i][j]){
				dfs(map, visited, n, i, j, number);
				++number;
			}
		}
	}
	int ans = MAX * MAX;
	for(int component = 1; component < number; ++component){
		memset(visited, false, sizeof(visited));
		int cmp = bfs(map, visited, n, component);
		if(cmp < ans){
			ans = cmp;
		}
	}
	printf("%d", ans);
	return 0;
}
