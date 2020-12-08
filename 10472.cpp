#include <cstdio>

int bits(int n){
	int ret = 0;
	for(int i = 0; i < 9; ++i){
		if(n % 2 == 1){
			++ret;
		}
		n /= 2;
	}
	return ret;
}

void flip(char grid[][4], int x, int y){
	int dx[4] = {0, 1, -1, 0};
	int dy[4] = {1, 0, 0, -1};
	grid[x][y] = (char)((int)'*' + '.' - grid[x][y]);
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
			grid[nx][ny] = (char)((int)'*' + '.' - grid[nx][ny]);
		}
	}
}

bool sol(char grid[][4], int x){
	char a[4][4];
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			a[i][j] = grid[i][j];
		}
	}
	for(int a0 = 0; a0 < 9; ++a0){
		if(x % 2 == 1){
			flip(a, a0 / 3, a0 % 3);
		}
		x /= 2;
	}
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(a[i][j] == '*'){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int p;
	scanf("%d", &p);
	for(int a0 = 0; a0 < p; ++a0){
		char grid[4][4];
		for(int i = 0; i < 3; ++i){
			scanf("%s", grid[i]);
		}
		int ans = 9;
		for(int x = 0; x < (1 << 9); ++x){
			int cmp = bits(x);
			if(cmp < ans && sol(grid, x)){
				ans = cmp;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
