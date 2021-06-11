#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#define MAX 301

using namespace std;

int bfs(char map[][MAX], int n, int m, vector<vector<pair<int, int>>> &slides, int sx, int sy){
	int dist[MAX][MAX];
	queue<int> q;
	bool visited[MAX][MAX] = {};
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	dist[sx][sy] = 0;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(map[x][y] == '='){
			return dist[x][y];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
				continue;
			}
			if(map[nx][ny] >= 'A' && map[nx][ny] <= 'Z'){
				char c = map[nx][ny];
				if(make_pair(nx, ny) == slides[c- 'A'][0]){
					nx = slides[c - 'A'][1].first;
					ny = slides[c - 'A'][1].second;
				}else{
					nx = slides[c - 'A'][0].first;
					ny = slides[c - 'A'][0].second;
				}
			}
			if(map[nx][ny] != '#' && !visited[nx][ny]){
				dist[nx][ny] = dist[x][y] + 1;
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	int x = -1, y = -1;
	vector<vector<pair<int, int>>> slides(26);
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < m; ++j){
			if(map[i][j] == '@'){
				x = i;
				y = j;
			}else if(map[i][j] >= 'A' && map[i][j] <= 'Z'){
				slides[map[i][j] - 'A'].push_back(make_pair(i, j));
			}
		}
	}
	printf("%d", bfs(map, n, m, slides, x, y));
	return 0;
}
