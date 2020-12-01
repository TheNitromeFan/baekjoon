#include <cstdio>
#include <queue>

using std::queue;

void traverse(char map[][101], bool visited[][101], int r, int c, int sx, int sy){
	int dx[4] = {0, 1, -1, 0};
	int dy[4] = {1, 0, 0, -1};
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == '1' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
}

int search(char map[][101], int r, int c){
	int ret = 0;
	bool visited[101][101] = {};
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] == '1' && !visited[i][j]){
				++ret;
				traverse(map, visited, r, c, i, j);
			}
		}
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		char grid[101][101];
		int r, c;
		scanf("%d %d", &r, &c);
		for(int i = 0; i < r; ++i){
			scanf("%s", grid[i]);
		}
		printf("Case #%d:\n", a0);
		int n;
		scanf("%d", &n);
		for(int j = 0; j < n; ++j){
			char op;
			scanf(" %c", &op);
			if(op == 'M'){
				int x, y, z;
				scanf("%d %d %d", &x, &y, &z);
				grid[x][y] = z + '0';
			}else if(op == 'Q'){
				printf("%d\n", search(grid, r, c));
			}
		}
	}
	return 0;
}
