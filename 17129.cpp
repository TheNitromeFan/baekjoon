#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 3001

using namespace std;

int food(char map[][MAX], int n, int m, int sx, int sy){
	queue<int> q;
	int visited[MAX][MAX];
	memset(visited, -1, sizeof(visited));
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(map[x][y] == '3' || map[x][y] == '4' || map[x][y] == '5'){
			return visited[x][y];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != '1' && visited[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
	return 0;
}

int main(){
	char map[MAX][MAX];
	int n, m;
	scanf("%d %d", &n, &m);
	int x = -1, y = -1;
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < m; ++j){
			if(map[i][j] == '2'){
				x = i;
				y = j;
			}
		}
	}
	int dist = food(map, n, m, x, y);
	if(dist > 0){
		printf("TAK\n%d", dist);
	}else{
		printf("NIE");
	}
	return 0;
}
