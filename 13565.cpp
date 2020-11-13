#include <cstdio>
#include <queue>
#define MAX (1000 + 1)

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool percolate(queue<int> q, char board[][MAX], bool visited[][MAX], int r, int c){
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == r - 1){
			return true;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == '0' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return false;
}

int main(){
	char board[MAX][MAX];
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; ++i){
		scanf("%s", board[i]);
	}
	queue<int> q;
	bool visited[MAX][MAX] = {};
	for(int j = 0; j < n; ++j){
		if(board[0][j] == '0'){
			q.push(0);
			q.push(j);
			visited[0][j] = true;
		}
	}
	printf("%s", percolate(q, board, visited, m, n) ? "YES" : "NO");
	return 0;
}
