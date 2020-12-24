#include <iostream>
#include <cstring>
#include <queue>
#define MAX 501

using namespace std;

void tour(int board[][MAX], int n, int sx, int sy){
	queue<int> q;
	int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	q.push(sx);
	q.push(sy);
	board[sx][sy] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && board[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				board[nx][ny] = board[x][y] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	int board[MAX][MAX];
	memset(board, -1, sizeof(board));
	tour(board, n, x, y);
	for(int j = 0; j < m; ++j){
		int a, b;
		cin >> a >> b;
		cout << board[a][b] << ' ';
	}
	return 0;
}
