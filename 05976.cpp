#include <cstdio>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
	int n;
	scanf("%d", &n);
	static int a[750][750] = {};
	int i = 0;
	int x = 0, y = 0;
	int dir = 0;
	while(true){
		++i;
		a[x][y] = i;
		if(i == n * n){
			break;
		}
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != 0){
			dir = (dir + 1) % 4;
			nx = x + dx[dir], ny = y + dy[dir];
		}
		x = nx;
		y = ny;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
