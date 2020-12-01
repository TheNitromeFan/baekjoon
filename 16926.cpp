#include <cstdio>

void rotate(int a[][300], int n, int m){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int b[300][300] = {};
	for(int i = 0; i < n / 2 && i < m / 2; ++i){
		int x = i, y = i;
		int dir = 0;
		while(true){
			int nx = x + dx[dir], ny = y + dy[dir];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && b[nx][ny] == 0){
				b[nx][ny] = a[x][y];
			}else{
				++dir;
				if(dir == 4){
					break;
				}
				nx = x + dx[dir];
				ny = y + dy[dir];
				b[nx][ny] = a[x][y];
			}
			x = nx;
			y = ny;
			// printf("%d %d\n", x, y);
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			a[i][j] = b[i][j];
		}
	}
}

int main(){
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	int a[300][300];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	for(int a0 = 0; a0 < r; ++a0){
		rotate(a, n, m);
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
