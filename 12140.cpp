#include <cstdio>

bool simulate_falling_off(char map[][101], int r, int c, int x, int y){
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	int i = -1;
	switch(map[x][y]){
		case '.':
			return false;
		case '^':
			i = 0;
			break;
		case '>':
			i = 1;
			break;
		case 'v':
			i = 2;
			break;
		case '<':
			i = 3;
			break;
	}
	while(x >= 0 && x < r && y >= 0 && y < c){
		x += dx[i];
		y += dy[i];
		if(x >= 0 && x < r && y >= 0 && y < c && map[x][y] != '.'){
			return false;
		}
	}
	return true;
}

int change_arrows(char map[][101], int r, int c){
	char dir[5] = "^>v<";
	int ans = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(simulate_falling_off(map, r, c, i, j)){
				++ans;
				int k = 0;
				while(k < 4){
					map[i][j] = dir[k];
					if(!simulate_falling_off(map, r, c, i, j)){
						break;
					}
					++k;
				}
				if(k == 4){
					return -1;
				}
			}
		}
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int r, c;
		scanf("%d %d", &r, &c);
		char map[101][101];
		for(int i = 0; i < r; ++i){
			scanf("%s", map[i]);
		}
		int ans = change_arrows(map, r, c);
		printf("Case #%d: ", a0);
		if(ans != -1){
			printf("%d", ans);
		}else{
			printf("IMPOSSIBLE");
		}
		printf("\n");
	}
	return 0;
}
