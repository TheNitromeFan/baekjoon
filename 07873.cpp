#include <cstdio>
#include <queue>
#define MAX (1000 + 1)

using namespace std;

void bfs(char map[][MAX], bool visited[][MAX], int n, int m, int sx, int sy){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x + 1 < n
		&& (map[x][y] == 'B' || map[x][y] == 'E' || map[x][y] == 'F')
		&& (map[x + 1][y] == 'C' || map[x + 1][y] == 'D' || map[x + 1][y] == 'F')
		&& !visited[x + 1][y]){
			q.push(x + 1);
			q.push(y);
			visited[x + 1][y] = true;
		}
		if(x - 1 >= 0
		&& (map[x][y] == 'C' || map[x][y] == 'D' || map[x][y] == 'F')
		&& (map[x - 1][y] == 'B' || map[x - 1][y] == 'E' || map[x - 1][y] == 'F')
		&& !visited[x - 1][y]){
			q.push(x - 1);
			q.push(y);
			visited[x - 1][y] = true;
		}
		if(y + 1 < m
		&& (map[x][y] == 'D' || map[x][y] == 'E' || map[x][y] == 'F')
		&& (map[x][y + 1] == 'B' || map[x][y + 1] == 'C' || map[x][y + 1] == 'F')
		&& !visited[x][y + 1]){
			q.push(x);
			q.push(y + 1);
			visited[x][y + 1] = true;
		}
		if(y - 1 >= 0
		&& (map[x][y] == 'B' || map[x][y] == 'C' || map[x][y] == 'F')
		&& (map[x][y - 1] == 'D' || map[x][y - 1] == 'E' || map[x][y - 1] == 'F')
		&& !visited[x][y - 1]){
			q.push(x);
			q.push(y - 1);
			visited[x][y - 1] = true;
		}
	}
}

int main(){
	int z;
	scanf("%d", &z);
	for(int a0 = 0; a0 < z; ++a0){
		int n, m;
		scanf("%d %d", &n, &m);
		char photo[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", photo[i]);
		}
		bool visited[MAX][MAX] = {};
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(photo[i][j] != 'A' && !visited[i][j]){
					++cnt;
					bfs(photo, visited, n, m, i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
