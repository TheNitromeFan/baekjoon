#include <iostream>
#include <algorithm>
#define MAX 51

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			map[i][j] = 2000000000;
		}
	}
	for(int a0 = 0; a0 < k; ++a0){
		int x, y, t;
		cin >> x >> y >> t;
		int dx[4] = {-1, 0, 1, 0};
		int dy[4] = {0, 1, 0, -1};
		if(t){
			swap(dy[1], dy[3]);
		}
		--x;
		--y;
		int dir = 0;
		int cnt = 0;
		int num = 0;
		int dcnt = 0, maxdcnt = 1;
		while(cnt < n * m){
			++num;
			if(x >= 0 && x < n && y >= 0 && y < m){
				map[x][y] = min(map[x][y], num);
				++cnt;
			}
			x += dx[dir];
			y += dy[dir];
			++dcnt;
			if(dcnt == maxdcnt){
				dir = (dir + 1) % 4;
				dcnt = 0;
				if(dir % 2 == 0){
					++maxdcnt;
				}
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
