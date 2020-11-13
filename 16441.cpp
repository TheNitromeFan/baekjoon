#include <cstdio>
#include <queue>
#define MAX (100 + 1)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(char map[][MAX], int r, int c){
	std::queue<int> q;
	bool visited[MAX][MAX];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] == 'W'){
				q.push(i);
				q.push(j);
				visited[i][j] = true;
			}else{
				visited[i][j] = false;
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
			while(map[nx][ny] == '+' && map[nx + dx[i]][ny + dy[i]] != '#'){
				nx += dx[i];
				ny += dy[i];
			}
			if((map[nx][ny] == '.' || map[nx][ny] == '+') && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] == '.' && !visited[i][j]){
				map[i][j] = 'P';
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	bfs(map, n, m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
