#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
#define MAX 50

using std::queue;
using std::pair;
using std::make_pair;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool traverse_board(int board[][MAX], int visited[][MAX], int sz, int sx, int sy, int left, int right){
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = 1;
	int population = 0;
	int component_size = 0;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		population += board[x][y];
		++component_size;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < sz && ny >= 0 && ny < sz &&
			abs(board[nx][ny] - board[x][y]) >= left &&
			abs(board[nx][ny] - board[x][y]) <= right && visited[nx][ny] == 0){
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
			}
		}
	}
	int people = population / component_size;
	// printf("%d\n", people);
	bool moved = false;
	q.push(make_pair(sx, sy));
	visited[sx][sy] = 2;
	board[sx][sy] = people;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < sz && ny >= 0 && ny < sz &&
			visited[nx][ny] == 1){
				if(board[nx][ny] != people){
					moved = true;
				}
				board[nx][ny] = people;
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 2;
			}
		}
	}
	return moved;
}

bool assign_components(int board[][MAX], int visited[][MAX], int sz, int left, int right){
	bool moved = false;
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			if(visited[i][j] == 0){
				moved |= traverse_board(board, visited, sz, i, j, left, right);
			}
		}
	}
	return moved;
}

/*
int traverse_components(int board[][MAX], int sz, int num[][MAX], int sx, int sy){
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	int population = 0;
	int component_size = 0;
	bool visited[MAX][MAX] = {};
	visited[sx][sy] = true;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		population += board[x][y];
		// printf("%d\n", population);
		++component_size;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < sz && ny >= 0 && ny < sz &&
			num[nx][ny] == num[sx][sy] && !visited[nx][ny]){
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	// printf("%d\n%d\n", population, component_size);
	return population / component_size;
}
*/

/*
void assign_board(int board[][MAX], int sz, int num[][MAX], int sx, int sy, int val){
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	bool visited[MAX][MAX] = {};
	visited[sx][sy] = true;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		board[x][y] = val;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < sz && ny >= 0 && ny < sz &&
			num[nx][ny] == num[sx][sy] && !visited[nx][ny]){
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}
*/

/*
void check_board(int board[][MAX], int sz, int num[][MAX]){
	int n = 1;
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			if(num[i][j] == n){
				int population = traverse_components(board, sz, num, i, j);
				assign_board(board, sz, num, i, j, population);
				++n;
			}
		}
	}
}
*/

int main(){
	int n, left, right;
	scanf("%d %d %d", &n, &left, &right);
	int c[MAX][MAX] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &c[i][j]);
		}
	}
	int moves = 0;
	while(true){
		int visited[MAX][MAX] = {};
		bool moved = assign_components(c, visited, n, left, right);
		if(!moved){
			break;
		}
		/*
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%d ", num[i][j]);
			}
			printf("\n");
		}
		*/
		// check_board(c, n, num);
		++moves;
		/*
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%d ", c[i][j]);
			}
			printf("\n");
		}
		*/
	}
	printf("%d", moves);
	return 0;
}
