#include <cstdio>
#define MAX 3002

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	char grid[MAX][MAX];
	for(int i = 0; i < h; ++i){
		scanf("%s", grid[i]);
	}
	int orbs[MAX][MAX] = {}, ingots[MAX][MAX] = {};
	for(int i = h - 1; i >= 0; --i){
		for(int j = w - 1; j >= 0; --j){
			orbs[i][j] = orbs[i][j + 1];
			if(grid[i][j + 1] == 'O'){
				++orbs[i][j];
			}
			ingots[i][j] = ingots[i + 1][j];
			if(grid[i + 1][j] == 'I'){
				++ingots[i][j];
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(grid[i][j] == 'J'){
				ans += orbs[i][j] * ingots[i][j];
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
