#include <cstdio>
#include <queue>
#define MAX 50

using std::queue;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int a[][MAX], int comp[][MAX], int r, int c, int sx, int sy, int rank){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	comp[sx][sy] = rank;
	int sz = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		++sz;
		int walls[4] = {a[x][y] % 2, a[x][y] / 2 % 2, a[x][y] / 4 % 2, a[x][y] / 8};
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && walls[i] == 0 && comp[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				comp[nx][ny] = rank;
			}
		}
	}
	return sz;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int castle[MAX][MAX] = {};
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &castle[i][j]);
		}
	}
	int comp[MAX][MAX];
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			comp[i][j] = -1;
		}
	}
	int sizes[MAX * MAX] = {};
	int comps = 0;
	int max_sz = 0;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(comp[i][j] == -1){
				int sz = bfs(castle, comp, m, n, i, j, comps);
				sizes[comps] = sz;
				++comps;
				if(max_sz < sz){
					max_sz = sz;
				}
			}
		}
	}
	/*
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d ", comp[i][j]);
		}
		printf("\n");
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d %d: %d %d %d %d\n", i, j, castle[i][j] % 2, castle[i][j] / 2 % 2,
			castle[i][j] / 4 % 2, castle[i][j] / 8);
		}
	}
	*/
	printf("%d\n%d\n", comps, max_sz);
	max_sz = 0;
	for(int i = 0; i < m; ++i){
		for(int j = i % 2; j < n; j += 2){
			int walls[4] = {castle[i][j] % 2, castle[i][j] / 2 % 2,
			castle[i][j] / 4 % 2, castle[i][j] / 8};
			for(int dir = 0; dir < 4; ++dir){
				int ni = i + dx[dir], nj = j + dy[dir];
				if(ni >= 0 && ni < m && nj >= 0 && nj < n && walls[dir] == 1
				&& comp[i][j] != comp[ni][nj]){
					int new_sz = sizes[comp[i][j]] + sizes[comp[ni][nj]];
					if(max_sz < new_sz){
						max_sz = new_sz;
					}
				}
			}
		}
	}
	printf("%d", max_sz);
	return 0;
}
