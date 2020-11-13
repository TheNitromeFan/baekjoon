#include <cstdio>
#define MAX (1000 + 1)

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

char minesweeper(char map[][MAX], int sz, int x, int y){
	if(map[x][y] != '.'){
		return '*';
	}
	int cnt = 0;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < sz && ny >= 0 && ny < sz && map[nx][ny] != '.'){
			cnt += map[nx][ny] - '0';
		}
	}
	if(cnt >= 10){
		return 'M';
	}
	return cnt + '0';
}

int main(){
	int n;
	scanf("%d", &n);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%c", minesweeper(map, n, i, j));
		}
		printf("\n");
	}
	return 0;
}
