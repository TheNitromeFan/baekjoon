#include <iostream>
#include <queue>
#include <cstring>
#define MAX 301

using namespace std;

int boosts(int a[][MAX], int n, int m){
	queue<int> q;
	int visited[MAX][MAX];
	memset(visited, -1, sizeof(visited));
	q.push(0);
	q.push(0);
	visited[0][0] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == n - 1 && y == m - 1){
			return visited[n - 1][m - 1];
		}
		for(int i = 1; i <= a[x][y] && x + i < n; ++i){
			if(visited[x + i][y] == -1){
				q.push(x + i);
				q.push(y);
				visited[x + i][y] = visited[x][y] + 1;
			}
		}
		for(int j = 1; j <= a[x][y] && y + j < m; ++j){
			if(visited[x][y + j] == -1){
				q.push(x);
				q.push(y + j);
				visited[x][y + j] = visited[x][y] + 1;
			}
		}
	}
	return -1;
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
	cout << boosts(a, n, m);
	return 0;
}
