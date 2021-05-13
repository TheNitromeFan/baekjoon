#include <iostream>
#define MAX 52

using namespace std;

void simulate(bool turner[][MAX], int n, int dx[4], int dy[4], int &x, int &y, int &dir){
	bool visited[MAX][MAX][4] = {};
	if(turner[x][y]){
		dir = (dir + 1) % 4;
	}
	visited[x][y][dir] = true;
	while(true){
		x += dx[dir];
		y += dy[dir];
		if(!(x >= 1 && x <= n && y >= 1 && y <= n)){
			return;
		}
		if(turner[x][y]){
			dir = (dir + 1) % 4;
		}
		if(visited[x][y][dir]){
			x = 0;
			y = 0;
			return;
		}
		visited[x][y][dir] = true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		bool turner[MAX][MAX] = {};
		int n, r;
		cin >> n >> r;
		for(int i = 0; i < r; ++i){
			int x, y;
			cin >> x >> y;
			turner[x][y] = true;
		}
		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};
		int x, y;
		cin >> x >> y;
		int dir = 0;
		if(x == n + 1){
			--x;
			dir = 0;
		}else if(y == 0){
			++y;
			dir = 1;
		}else if(x == 0){
			++x;
			dir = 2;
		}else{
			--y;
			dir = 3;
		}
		simulate(turner, n, dx, dy, x, y, dir);
		cout << x << ' ' << y << '\n';
	}
	return 0;
}
