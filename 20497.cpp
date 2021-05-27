#include <cstdio>
#include <queue>
#define MAX 12

using namespace std;

void bfs(char map[][MAX], bool visited[][MAX], int n, int sx, int sy){
	queue<int> q;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
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
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == '.' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
}

int components(char map[][MAX], int n){
	bool visited[MAX][MAX] = {};
	int ret = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] == '.' && !visited[i][j]){
				bfs(map, visited, n, i, j);
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int cmp1 = components(map, n);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] == '.'){
				map[i][j] = '@';
				int cmp2 = components(map, n);
				if(cmp2 > cmp1){
					++ans;
				}
				map[i][j] = '.';
			}
		}
	}
	printf("%d", ans);
	return 0;
}
