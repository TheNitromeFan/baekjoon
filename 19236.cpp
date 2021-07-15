#include <iostream>
#include <algorithm>

using namespace std;

struct Fish{
	int x;
	int y;
	int d;
	bool eaten;
};

void move_fish(int map[][4], Fish fish[17], int dx[9], int dy[9], int x, int y){
	for(int n = 1; n <= 16; ++n){
		if(fish[n].eaten){
			continue;
		}
		for(int i = 0; i < 8; ++fish[n].d, ++i){
			if(fish[n].d == 9){
				fish[n].d = 1;
			}
			int nx = fish[n].x + dx[fish[n].d];
			int ny = fish[n].y + dy[fish[n].d];
			if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !(nx == x && ny == y)){
				int m = map[nx][ny];
				swap(map[fish[n].x][fish[n].y], map[nx][ny]);
				swap(fish[n].x, fish[m].x);
				swap(fish[n].y, fish[m].y);
				break;
			}
		}
	}
}

void simulate(int map[][4], Fish fish[17], int dx[9], int dy[9], int x, int y, int sum, int &max_sum){
	sum += map[x][y];
	int d = fish[map[x][y]].d;
	fish[map[x][y]].eaten = true;
	int map_copy[4][4];
	Fish fish_copy[17];
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			map_copy[i][j] = map[i][j];
		}
	}
	for(int n = 1; n <= 16; ++n){
		fish_copy[n].x = fish[n].x;
		fish_copy[n].y = fish[n].y;
		fish_copy[n].d = fish[n].d;
		fish_copy[n].eaten = fish[n].eaten;
	}
	move_fish(map_copy, fish_copy, dx, dy, x, y);
	int nx = x;
	int ny = y;
	while(nx >= 0 && nx < 4 && ny >= 0 && ny < 4){
		if(!fish[map_copy[nx][ny]].eaten){
			simulate(map_copy, fish_copy, dx, dy, nx, ny, sum, max_sum);
		}
		nx += dx[d];
		ny += dy[d];
	}
	max_sum = max(max_sum, sum);
	fish[map[x][y]].eaten = false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int map[4][4];
	Fish fish[17];
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			int dir;
			cin >> map[i][j] >> dir;
			fish[map[i][j]].x = i;
			fish[map[i][j]].y = j;
			fish[map[i][j]].d = dir;
			fish[map[i][j]].eaten = false;
		}
	}
	int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
	int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
	int ans = 0;
	simulate(map, fish, dx, dy, 0, 0, 0, ans);
	cout << ans << '\n';
	return 0;
}
