#include <iostream>
#define MAX 101

using namespace std;

int paintball(int map[][MAX], int n, int x, int y){
	int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int cnt = map[x][y];
	for(int i = 0; i < 8; ++i){
		int nx = x, ny = y;
		while(true){
			nx += dx[i];
			ny += dy[i];
			if(!(nx > 0 && nx <= n && ny > 0 && ny <= n)){
				break;
			}
			cnt += map[nx][ny];
		}
	}
	return cnt;
}

int locations(int map[][MAX], int n, int k){
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(paintball(map, n, i, j) == k){
				++cnt;
			}
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int map[MAX][MAX] = {};
	for(int i = 0; i < k; ++i){
		int x, y;
		cin >> x >> y;
		++map[x][y];
	}
	cout << locations(map, n, k);
	return 0;
}
