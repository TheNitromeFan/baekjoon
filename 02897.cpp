#include <cstdio>
#define MAX (50 + 1)

int squashed(char map[][MAX], int startx, int starty){
	int ret = 0;
	for(int x = startx; x < startx + 2; ++x){
		for(int y = starty; y < starty + 2; ++y){
			if(map[x][y] == 'X'){
				++ret;
			}
		}
	}
	return ret;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char park[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", park[i]);
	}
	int ans[5] = {};
	for(int i = 0; i < r - 1; ++i){
		for(int j = 0; j < c - 1; ++j){
			if(park[i][j] == '#' || park[i][j + 1] == '#' || park[i + 1][j] == '#' || park[i + 1][j + 1] == '#'){
				continue;
			}
			++ans[squashed(park, i, j)];
		}
	}
	for(int idx = 0; idx < 5; ++idx){
		printf("%d\n", ans[idx]);
	}
	return 0;
}
