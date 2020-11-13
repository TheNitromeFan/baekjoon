#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int grid[1000][1000];
bool visited[1000][1000][2];

int bfs(int n, int m){
	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 1));
	visited[0][0][0] = true;
	while(!q.empty()){
		tuple<int, int, int, int> tmp = q.front();
		q.pop();
		int x = get<0>(tmp);
		int y = get<1>(tmp);
		int w = get<2>(tmp);
		int cnt = get<3>(tmp);
		if(x == n-1 && y == m-1){
			return cnt;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && ny >= 0 && nx < n && ny < m){
				if(grid[nx][ny] == 1 && w == 0){
					visited[nx][ny][1] = true;
					q.push(make_tuple(nx, ny, 1, cnt+1));
				}else if(grid[nx][ny] == 0 && !visited[nx][ny][w]){
					visited[nx][ny][w] = true;
					q.push(make_tuple(nx, ny, w, cnt+1));
				}
			}
		}
	}
	return -1;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		char s[1001];
		scanf("%s", s);
		for(int j = 0; j < m; ++j){
			grid[i][j] = s[j] - '0';
		}
	}
	printf("%d", bfs(n, m));
	return 0;
}
