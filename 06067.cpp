#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#define MAX 701

using namespace std;

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void traverse(int h[][MAX], bool visited[][MAX], int n, int m, int sx, int sy){
	queue<int> q;
	q.push(sx);
	q.push(sy);
	visited[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 8; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && h[nx][ny] <= h[x][y]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int h[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> h[i][j];
		}
	}
	vector<pair<int, int>> coor;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			coor.push_back(make_pair(i, j));
		}
	}
	sort(coor.begin(), coor.end(), [&h](pair<int, int> p1, pair<int, int> p2){
		return h[p1.first][p1.second] > h[p2.first][p2.second];
	});
	bool visited[MAX][MAX] = {};
	int cnt = 0;
	for(pair<int, int> p : coor){
		int i = p.first, j = p.second;
		if(!visited[i][j]){
			++cnt;
			traverse(h, visited, n, m, i, j);
		}
	}
	cout << cnt;
	return 0;
}
