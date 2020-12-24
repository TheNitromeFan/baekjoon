#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define SIZE 8

using namespace std;

int moves(int x1, int y1, int x2, int y2){
	queue<int> q;
	int board[SIZE][SIZE];
	memset(board, -1, sizeof(board));
	int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	q.push(x1);
	q.push(y1);
	board[x1][y1] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == x2 && y == y2){
			return board[x][y];
		}
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				board[nx][ny] = board[x][y] + 1;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;
	cout << moves(s1[0] - 'a', s1[1] - '1', s2[0] - 'a', s2[1] - '1');
	return 0;
}
