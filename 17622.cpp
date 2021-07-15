#include <iostream>
#define MAX 51

using namespace std;

int simulate(int map[][MAX], int dx[4], int dy[4], int n){
	int len = 0;
	int x = 1, y = 0;
	int dir = 0;
	while(!(x == n && y == n)){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(!(nx >= 1 && nx <= n && ny >= 1 && ny <= n)){
			return -1;
		}
		if(dir == 0 && map[nx][ny] == 1){
			dir = 2;
		}else if(dir == 0 && map[nx][ny] == 3){
			dir = 3;
		}else if(dir == 0 && map[nx][ny] == 5){
			dir = 0;
		}else if(dir == 1 && map[nx][ny] == 0){
			dir = 2;
		}else if(dir == 1 && map[nx][ny] == 2){
			dir = 3;
		}else if(dir == 1 && map[nx][ny] == 5){
			dir = 1;
		}else if(dir == 2 && map[nx][ny] == 2){
			dir = 0;
		}else if(dir == 2 && map[nx][ny] == 3){
			dir = 1;
		}else if(dir == 2 && map[nx][ny] == 4){
			dir = 2;
		}else if(dir == 3 && map[nx][ny] == 0){
			dir = 0;
		}else if(dir == 3 && map[nx][ny] == 1){
			dir = 1;
		}else if(dir == 3 && map[nx][ny] == 4){
			dir = 3;
		}else{
			return -1;
		}
		x = nx;
		y = ny;
		++len;
	}
	return dir == 0 ? len : -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int map[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> map[i][j];
		}
	}
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	int ans = -1;
	if(k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				for(int k = 0; k < 6; ++k){
					if(map[i][j] == k){
						continue;
					}
					int tmp = map[i][j];
					map[i][j] = k;
					int cmp = simulate(map, dx, dy, n);
					if(cmp != -1 && (ans == -1 || ans > cmp)){
						ans = cmp;
					}
					map[i][j] = tmp;
				}
			}
		}
	}else{
		ans = simulate(map, dx, dy, n);
	}
	cout << ans << '\n';
	return 0;
}
