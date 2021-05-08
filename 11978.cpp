#include <iostream>
#include <cstring>
#define MAX 3000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int map[MAX][MAX];
	memset(map, -1, sizeof(map));
	int x = 1500, y = 1500;
	map[x][y] = 0;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	int time = 0;
	int ans = -1;
	for(int a0 = 0; a0 < n; ++a0){
		char dir;
		int steps;
		cin >> dir >> steps;
		int i = 3;
		if(dir == 'N'){
			i = 0;
		}else if(dir == 'S'){
			i = 1;
		}else if(dir == 'E'){
			i = 2;
		}
		for(int j = 0; j < steps; ++j){
			int nx = x + dx[i], ny = y + dy[i];
			++time;
			if(map[nx][ny] != -1 && (ans == -1 || ans > time - map[nx][ny])){
				ans = time - map[nx][ny];
			}
			x = nx;
			y = ny;
			map[x][y] = time;
		}
	}
	cout << ans;
	return 0;
}
