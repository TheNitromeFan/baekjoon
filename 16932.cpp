#include <iostream>
#include <queue>
#include <unordered_set>
#define MAX 1000

using namespace std;

void bfs(int a[][MAX], int b[][MAX], int c[MAX * MAX], bool visited[][MAX], int n, int m, int sx, int sy, int dx[4], int dy[4], int v){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	int size = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		++size;
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
				continue;
			}
			if(a[nx][ny] && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
	q.push(sx);
	q.push(sy);
	b[sx][sy] = v;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
				continue;
			}
			if(a[nx][ny] && b[nx][ny] == 0){
				q.push(nx);
				q.push(ny);
				b[nx][ny] = v;
			}
		}
	}
	c[v] = size;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}
	int b[MAX][MAX] = {};
	int c[MAX * MAX] = {};
	bool visited[MAX][MAX] = {};
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j] && b[i][j] == 0){
				++cnt;
				bfs(a, b, c, visited, n, m, i, j, dx, dy, cnt);
			}
		}
	}
	/*
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	/*
	for(int idx = 1; idx <= cnt; ++idx){
		cout << c[idx] << ' ';
	}
	cout << '\n';
	*/
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(!a[i][j]){
				int cmp = 1;
				unordered_set<int> us;
				for(int k = 0; k < 4; ++k){
					int nx = i + dx[k], ny = j + dy[k];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny]){
						us.insert(b[nx][ny]);
					}
				}
				for(int z : us){
					cmp += c[z];
					// cout << z << ' ' << c[z] << '\n';
				}
				if(ans < cmp){
					ans = cmp;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
