#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 8

using namespace std;

bool dir[6][4] = {{false, false, false, false},
				  {true, false, false, false},
				  {true, false, true, false},
				  {true, true, false, false},
				  {true, true, true, false},
				  {true, true, true, true}};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void copy(int map[][MAX], int map_copy[][MAX], int n, int m){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			map_copy[i][j] = map[i][j];
		}
	}
}

int count_blind_spots(int map[][MAX], int n, int m){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] == 0){
				++ret;
			}
		}
	}
	return ret;
}

int blind_spots(int map[][MAX], vector<pair<int, int>> &cctv, vector<int> &angles, int n, int m){
	int ret = -1;
	if(angles.size() == cctv.size()){
		int map_copy[MAX][MAX];
		copy(map, map_copy, n, m);
		for(unsigned i = 0; i < angles.size(); ++i){
			pair<int, int> camera = cctv[i];
			int type = map[camera.first][camera.second];
			for(int d = 0; d < 4; ++d){
				int angle = (angles[i] + d) % 4;
				if(!dir[type][angle]){
					continue;
				}
				int x = camera.first, y = camera.second;
				while(x >= 0 && x < n && y >= 0 && y < m && map_copy[x][y] != 6){
					if(map_copy[x][y] == 0){
						map_copy[x][y] = -1;
					}
					x += dx[d];
					y += dy[d];
				}
			}
		}
		return count_blind_spots(map_copy, n, m);
	}
	int cmp;
	for(int rotation = 0; rotation < 4; ++rotation){
		angles.push_back(rotation);
		cmp = blind_spots(map, cctv, angles, n, m);
		if(ret == -1 || ret > cmp){
			ret = cmp;
		}
		angles.pop_back();
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int map[MAX][MAX];
	vector<pair<int, int>> cctv;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] >= 1 && map[i][j] <= 5){
				cctv.push_back(make_pair(i, j));
			}
		}
	}
	vector<int> angles;
	printf("%d", blind_spots(map, cctv, angles, n, m));
	return 0;
}
