#include <iostream>
#define MAX 5000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	bool grid[MAX][MAX] = {};
	int cnt = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int dir = 0;
	grid[0][0] = true;
	++cnt;
	int x = 0, y = 0;
	while(cnt < n * m){
		int nx = x + dx[dir], ny = y + dy[dir];
		if(!(nx >= 0 && nx < n && ny >= 0 && ny < m && !grid[nx][ny])){
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;
		grid[x][y] = true;
		++cnt;
	}
	cout << x << ' ' << y;
	return 0;
}
