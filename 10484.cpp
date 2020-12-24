#include <iostream>
#include <queue>
#include <cstring>
#define MAX 400

using namespace std;

int steps(bool map[MAX][MAX], int startx, int starty, int endx, int endy){
	queue<int> q;
	int dist[MAX][MAX];
	memset(dist, -1, sizeof(dist));
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	q.push(startx);
	q.push(starty);
	dist[startx][starty] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == endx && y == endy){
			return dist[x][y] / 2;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(map[nx][ny] && dist[nx][ny] == -1){
				q.push(nx);
				q.push(ny);
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		bool map[MAX][MAX] = {};
		int startx = MAX / 2, starty = MAX / 2;
		int x = startx, y = starty;
		map[x][y] = true;
		int s;
		cin >> s;
		for(int i = 0; i < s; ++i){
			char dir;
			cin >> dir;
			switch(dir){
				case 'N':
					++y;
					map[x][y] = true;
					++y;
					break;
				case 'S':
					--y;
					map[x][y] = true;
					--y;
					break;
				case 'E':
					++x;
					map[x][y] = true;
					++x;
					break;
				case 'W':
					--x;
					map[x][y] = true;
					--x;
					break;
			}
			map[x][y] = true;
		}
		int endx = x, endy = y;
		cout << steps(map, startx, starty, endx, endy) << '\n';
	}
	return 0;
}
