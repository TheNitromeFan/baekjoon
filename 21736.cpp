#include <cstdio>
#include <queue>
#define MAX 601

using namespace std;

int meet(char map[][MAX], int n, int m, int sx, int sy){
	queue<int> q;
	bool visited[MAX][MAX] = {};
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	int met = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(map[x][y] == 'P'){
			++met;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 'X' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return met;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	int x = -1, y = -1;
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < m; ++j){
			if(map[i][j] == 'I'){
				x = i;
				y = j;
			}
		}
	}
	int ans = meet(map, n, m, x, y);
	if(ans > 0){
		printf("%d", ans);
	}else{
		printf("TT");
	}
	return 0;
}
