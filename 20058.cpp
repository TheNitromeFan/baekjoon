#include <iostream>
#include <queue>
#define MAX (1 << 6)

using namespace std;

void rotate_block(int a[][MAX], int block_sz, int x, int y){
	int b[MAX][MAX];
	for(int i = x; i < x + block_sz; ++i){
		for(int j = y; j < y + block_sz; ++j){
			b[i][j] = a[x + block_sz - 1 - j + y][y + i - x];
		}
	}
	for(int i = x; i < x + block_sz; ++i){
		for(int j = y; j < y + block_sz; ++j){
			a[i][j] = b[i][j];
		}
	}
}

void rotate_array(int a[][MAX], int sz, int block_sz){
	for(int i = 0; i < sz; i += block_sz){
		for(int j = 0; j < sz; j += block_sz){
			rotate_block(a, block_sz, i, j);
		}
	}
}

void melt(int a[][MAX], int sz, int dx[4], int dy[4]){
	int b[MAX][MAX];
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			b[i][j] = a[i][j];
			int neighbors = 0;
			for(int k = 0; k < 4; ++k){
				int ni = i + dx[k], nj = j + dy[k];
				if(ni >= 0 && ni < sz && nj >= 0 && nj < sz && a[ni][nj] > 0){
					++neighbors;
				}
			}
			if(neighbors < 3){
				--b[i][j];
			}
		}
	}
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			a[i][j] = b[i][j];
		}
	}
}

int bfs(int a[][MAX], bool visited[][MAX], int sz, int sx, int sy, int dx[4], int dy[4], int &sum){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	sum += a[sx][sy];
	int ret = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		// cout << x << ' ' << y << '\n';
		++ret;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < sz && ny >= 0 && ny < sz && a[nx][ny] > 0 && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
				sum += a[nx][ny];
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int sz = (1 << n);
	int a[MAX][MAX];
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			cin >> a[i][j];
		}
	}
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int a0 = 0; a0 < q; ++a0){
		int level;
		cin >> level;
		rotate_array(a, sz, 1 << level);
		/*
		for(int i = 0; i < sz; ++i){
			for(int j = 0; j < sz; ++j){
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		*/
		melt(a, sz, dx, dy);
		/*
		for(int i = 0; i < sz; ++i){
			for(int j = 0; j < sz; ++j){
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		*/
	}
	int sum = 0, max_area = 0;
	bool visited[MAX][MAX] = {};
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			if(a[i][j] > 0 && !visited[i][j]){
				int cmp = bfs(a, visited, sz, i, j, dx, dy, sum);
				if(max_area < cmp){
					max_area = cmp;
				}
			}
		}
	}
	cout << sum << '\n' << max_area;
	return 0;
}
