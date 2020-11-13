#include <cstdio>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>

using namespace std;

void hunt(vector<tuple<int, int, int>> ocean[][101], int r, int j, int &hunted){
	for(int i = 1; i <= r; ++i){
		if(!ocean[i][j].empty()){
			hunted += get<0>(ocean[i][j][0]);
			ocean[i][j].clear();
			break;
		}
	}
}

void swim_shark(int r, int c, int &x, int &y, int speed, int &dir){
	if(dir == 1 || dir == 2){
		speed %= 2 * (r - 1);
	}else if(dir == 3 || dir == 4){
		speed %= 2 * (c - 1);
	}
	for(int i = 0; i < speed; ++i){
		if(dir == 1){
			if(x == 1){
				dir = 2;
				++x;
			}else{
				--x;
			}
		}else if(dir == 2){
			if(x == r){
				dir = 1;
				--x;
			}else{
				++x;
			}
		}else if(dir == 3){
			if(y == c){
				dir = 4;
				--y;
			}else{
				++y;
			}
		}else if(dir == 4){
			if(y == 1){
				dir = 3;
				++y;
			}else{
				--y;
			}
		}
	}
}

void swim(vector<tuple<int, int, int>> ocean[][101], int r, int c){
	vector<tuple<int, int, int>> map[101][101];
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= c; ++j){
			for(tuple<int, int, int> shark: ocean[i][j]){
				int sz = get<0>(shark), speed = get<1>(shark), dir = get<2>(shark);
				int x = i, y = j;
				swim_shark(r, c, x, y, speed, dir);
				map[x][y].push_back(make_tuple(sz, speed, dir));
			}
		}
	}
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= c; ++j){
			if(map[i][j].size() > 1){
				sort(map[i][j].begin(), map[i][j].end(), greater<tuple<int, int, int>>());
				tuple<int, int, int> shark = map[i][j][0];
				map[i][j].clear();
				map[i][j].push_back(shark);
			}
			ocean[i][j] = map[i][j];
		}
	}
}

int main(){
	int r, c, m;
	scanf("%d %d %d", &r, &c, &m);
	vector<tuple<int, int, int>> ocean[101][101];
	for(int a0 = 0; a0 < m; ++a0){
		int i, j, s, d, z;
		scanf("%d %d %d %d %d", &i, &j, &s, &d, &z);
		ocean[i][j].push_back(make_tuple(z, s, d));
	}
	int caught = 0;
	for(int j = 1; j <= c; ++j){
		hunt(ocean, r, j, caught);
		swim(ocean, r, c);
	}
	printf("%d", caught);
	return 0;
}
