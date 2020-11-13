#include <cstdio>
#define MAX 100

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int arr[MAX][MAX] = {};
	int x = 0, y = 0, dir = 0;
	int ans = 0;
	for(int i = 1; i <= m * n; ++i){
		arr[x][y] = i;
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 0 || nx >= m || ny < 0 || ny >= n || arr[nx][ny] != 0){
			++ans;
			dir = (dir + 1) % 4;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		x = nx;
		y = ny;
	}
	printf("%d", ans - 1);
	return 0;
}
