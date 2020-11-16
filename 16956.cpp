#include <cstdio>

bool fence(char map[][501], int n, int m){
	int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(map[i][j] == 'S'){
				for(int k = 0; k < 4; ++k){
					int x = i + dx[k], y = j + dy[k];
					if(x >= 0 && x < n && y >= 0 && y < m){
						if(map[x][y] == 'W'){
							return false;
						}else if(map[x][y] == '.'){
							map[x][y] = 'D';
						}
					}
				}
			}
		}
	}
	return true;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[501][501];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	bool safe = fence(map, r, c);
	printf("%d\n", safe);
	if(safe){
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
