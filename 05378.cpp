#include <cstdio>
#include <queue>
#define MAX 101

using namespace std;

bool black(char map[][MAX], int dx[6], int dy[6], int n){
	queue<int> q;
	bool visited[MAX][MAX] = {};
	for(int j = 0; j < n; ++j){
		if(map[0][j] == 'B'){
			q.push(0);
			q.push(j);
			visited[0][j] = true;
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == n - 1){
			return true;
		}
		for(int i = 0; i < 6; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 'B' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return false;
}

bool white(char map[][MAX], int dx[6], int dy[6], int n){
	queue<int> q;
	bool visited[MAX][MAX] = {};
	for(int j = 0; j < n; ++j){
		if(map[j][0] == 'W'){
			q.push(j);
			q.push(0);
			visited[j][0] = true;
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(y == n - 1){
			return true;
		}
		for(int i = 0; i < 6; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 'W' && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	int dx[6] = {-1, -1, 0, 1, 1, 0};
	int dy[6] = {1, 0, -1, -1, 0, 1};
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		char board[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", board[i]);
		}
		if(black(board, dx, dy, n)){
			printf("Black wins\n");
		}else if(white(board, dx, dy, n)){
			printf("White wins\n");
		}else{
			printf("Not finished\n");
		}
	}
	return 0;
}
