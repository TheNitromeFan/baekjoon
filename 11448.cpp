#include <cstdio>
#include <queue>

using std::queue;

int component(char map[][101], bool visited[][101], int n, int sx, int sy){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	int ans = -1;
	int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
	int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		++ans;
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == '-' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		char board[101][101];
		for(int i = 0; i < n; ++i){
			scanf("%s", board[i]);
		}
		int stones = 0;
		bool visited[101][101] = {};
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(board[i][j] == 'w' && !visited[i][j]){
					stones += component(board, visited, n, i, j);
				}
			}
		}
		printf("%d\n", stones);
	}
	return 0;
}
