#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101

using namespace std;

bool maze(int map[][MAX], int h, int w, int xs, int ys, int xe, int ye, int f){
	int force[MAX][MAX];
	memset(force, -1, sizeof(force));
	queue<int> q;
	force[xs][ys] = f;
	q.push(xs);
	q.push(ys);
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		if(x == xe && y == ye){
			return true;
		}
		if(force[x][y] == 0){
			continue;
		}
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 1 && nx <= h && ny >= 1 && ny <= w && force[nx][ny] == -1)){
				continue;
			}
			if(force[x][y] >= map[nx][ny] - map[x][y]){
				q.push(nx);
				q.push(ny);
				force[nx][ny] = force[x][y] - 1;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int h, w, obs, f, xs, ys, xe, ye;
		cin >> h >> w >> obs >> f >> xs >> ys >> xe >> ye;
		int map[MAX][MAX] = {};
		for(int a1 = 0; a1 < obs; ++a1){
			int x, y, len;
			cin >> x >> y >> len;
			map[x][y] = len;
		}
		cout << (maze(map, h, w, xs, ys, xe, ye, f) ? "잘했어!!" : "인성 문제있어??") << '\n';
	}
	return 0;
}
