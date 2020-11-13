#include <cstdio>
#include <queue>
#define MAX (100 + 1)

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int map[][MAX], int r, int c, int time){
	queue<int> q;
	int visited[MAX][MAX][2] = {};
	q.push(1);
	q.push(1);
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int sword = q.front();
		q.pop();
		if(x == r && y == c){
			return visited[x][y][sword];
		}else if(visited[x][y][sword] == time){
			break;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx <= 0 || nx > r || ny <= 0 || ny > c){
				continue;
			}
			if(sword == 0){
				int nsword = 0;
				if(map[nx][ny] == 1){
					continue;
				}else if(map[nx][ny] == 2){
					nsword = 1;
				}
				if((nx == 1 && ny == 1 && nsword == 0) || visited[nx][ny][nsword] != 0){
					continue;
				}
				visited[nx][ny][nsword] = visited[x][y][0] + 1;
				q.push(nx);
				q.push(ny);
				q.push(nsword);
			}else{
				if(visited[nx][ny][1] != 0){
					continue;
				}
				visited[nx][ny][1] = visited[x][y][1] + 1;
				q.push(nx);
				q.push(ny);
				q.push(1);
			}
		}
	}
	return -1;
}

int main(){
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);
	int castle[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			scanf("%d", &castle[i][j]);
		}
	}
	int ans = bfs(castle, n, m, t);
	if(ans == -1){
		printf("Fail");
	}else{
		printf("%d", ans);
	}
	return 0;
}
