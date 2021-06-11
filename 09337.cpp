#include <cstdio>
#include <queue>
#define MAX 21

using namespace std;

int initialize(int map[][MAX], bool visited[][MAX], int dx[4], int dy[4], int n){
	queue<int> q;
	q.push(0);
	q.push(0);
	visited[0][0] = true;
	int ret = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		++ret;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && map[nx][ny] == map[x][y]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return ret;
}

int check_candidate(int map[][MAX], bool visited[][MAX], int dx[4], int dy[4], int n, int color){
	queue<int> q;
	bool visited1[MAX][MAX];
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < n; ++y){
			if(visited[x][y]){
				q.push(x);
				q.push(y);
			}
			visited1[x][y] = visited[x][y];
		}
	}
	int cnt = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited1[nx][ny] && map[nx][ny] == color){
				++cnt;
				q.push(nx);
				q.push(ny);
				visited1[nx][ny] = true;
			}
		}
	}
	return cnt;
}

void flood_fill(int map[][MAX], bool visited[][MAX], int dx[4], int dy[4], int n, int color){
	queue<int> q;
	for(int x = 0; x < n; ++x){
		for(int y = 0; y < n; ++y){
			if(visited[x][y]){
				q.push(x);
				q.push(y);
			}
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && map[nx][ny] == color){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int map[MAX][MAX];
		for(int i = 0; i < n; ++i){
			char line[MAX];
			scanf("%s", line);
			for(int j = 0; j < n; ++j){
				map[i][j] = line[j] - '0';
			}
		}
		bool visited[MAX][MAX] = {};
		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		int squares = initialize(map, visited, dx, dy, n);
		int cnt = 0;
		int ans[7] = {};
		while(squares < n * n){
			int next_color = -1, next_cnt = 0;
			for(int color = 1; color <= 6; ++color){
				int cmp = check_candidate(map, visited, dx, dy, n, color);
				if(cmp > next_cnt){
					next_color = color;
					next_cnt = cmp;
				}
			}
			squares += next_cnt;
			++cnt;
			++ans[next_color];
			flood_fill(map, visited, dx, dy, n, next_color);
		}
		printf("%d\n", cnt);
		for(int color = 1; color <= 6; ++color){
			printf("%d ", ans[color]);
		}
		printf("\n");
	}
	return 0;
}
