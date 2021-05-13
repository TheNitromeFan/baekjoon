#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 110
#define MAXVAL 1000000000

using namespace std;

void erupt(int time_limit[][MAX], int m, int n, int xi, int yi, int ti, int dx[4], int dy[4]){
	queue<int> q;
	bool visited[MAX][MAX] = {};
	int new_time_limit[MAX][MAX];
	q.push(xi);
	q.push(yi);
	visited[xi][yi] = true;
	new_time_limit[xi][yi] = ti;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= m && ny >= 1 && ny <= n && !visited[nx][ny]){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
				new_time_limit[nx][ny] = new_time_limit[x][y] + 1;
			}
		}
	}
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			time_limit[i][j] = min(time_limit[i][j], new_time_limit[i][j]);
		}
	}
	time_limit[xi][yi] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, v, x0, y0;
	cin >> m >> n >> v >> x0 >> y0;
	int map[MAX][MAX];
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> map[i][j];
		}
	}
	int time_limit[MAX][MAX];
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			time_limit[i][j] = MAXVAL;
		}
	}
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int k = 0; k < v; ++k){
		int xi, yi, ti;
		cin >> xi >> yi >> ti;
		erupt(time_limit, m, n, xi, yi, ti, dx, dy);
	}
	/*
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			cout << time_limit[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	queue<int> q;
	bool visited[MAX][MAX] = {};
	q.push(x0);
	q.push(y0);
	visited[x0][y0] = true;
	int max_height = map[x0][y0], min_time = 0;
	int travel_time[MAX][MAX] = {};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(map[x][y] > max_height || (map[x][y] == max_height && travel_time[x][y] < min_time)){
			max_height = map[x][y];
			min_time = travel_time[x][y];
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= m && ny >= 1 && ny <= n && !visited[nx][ny]
			&& time_limit[nx][ny] > travel_time[x][y] + 1){
				q.push(nx);
				q.push(ny);
				visited[nx][ny] = true;
				travel_time[nx][ny] = travel_time[x][y] + 1;
			}
		}
	}
	cout << max_height << ' ' << min_time;
	return 0;
}
