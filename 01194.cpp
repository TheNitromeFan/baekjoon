#include <cstdio>
#include <queue>
#define MAX (50 + 1)

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(char map[][MAX], int n, int m, int sx, int sy){
	queue<int> q;
	int visited[MAX][MAX][1 << 6] = {};
	q.push(sx);
	q.push(sy);
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int keys = q.front();
		q.pop();
		if(map[x][y] == '1'){
			return visited[x][y][keys];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i], nkeys = keys;
			if(nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#'){
				continue;
			}
			if(map[nx][ny] >= 'a' && map[nx][ny] <= 'f'){
				nkeys |= (1 << (map[nx][ny] - 'a'));
			}else if(map[nx][ny] >= 'A' && map[nx][ny] <= 'f' && ((nkeys & (1 << (map[nx][ny] - 'A'))) == 0)){
				continue;
			}
			if(!(nx == sx && ny == sy && nkeys == 0) && visited[nx][ny][nkeys] == 0){
				visited[nx][ny][nkeys] = visited[x][y][keys] + 1;
				q.push(nx);
				q.push(ny);
				q.push(nkeys);
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	int startx = 0, starty = 0;
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < m; ++j){
			if(map[i][j] == '0'){
				startx = i;
				starty = j;
			}
		}
	}
	printf("%d", bfs(map, n, m, startx, starty));
	return 0;
}
