#include <cstdio>

int main(){
	int t = 0;
	while(true){
		int w, l;
		scanf("%d %d", &w, &l);
		if(w == 0 && l == 0){
			break;
		}
		++t;
		char house[30][30];
		int x = 0, y = 0;
		for(int i = 0; i < l; ++i){
			scanf("%s", house[i]);
			for(int j = 0; j < w; ++j){
				if(house[i][j] == '*'){
					x = i;
					y = j;
				}
			}
		}
		int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
		int dir = 3;
		if(x == 0){
			dir = 0;
		}else if(y == 0){
			dir = 1;
		}else if(y == w - 1){
			dir = 2;
		}
		while(true){
			x += dx[dir];
			y += dy[dir];
			if(x == 0 || x == l - 1 || y == 0 || y == w - 1){
				house[x][y] = '&';
				break;
			}else if(house[x][y] == '\\'){
				dir = (5 - dir) % 4;
			}else if(house[x][y] == '/'){
				dir = (2 + dir) % 4;
			}
		}
		printf("HOUSE %d\n", t);
		for(int i = 0; i < l; ++i){
			printf("%s\n", house[i]);
		}
	}
	return 0;
}
