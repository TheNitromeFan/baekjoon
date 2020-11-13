#include <cstdio>
#define MAX (50 + 1)

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
	int r, s;
	scanf("%d %d", &r, &s);
	char seat[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", seat[i]);
	}
	int shakes[MAX][MAX] = {};
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < s; ++j){
			if(seat[i][j] == 'o'){
				for(int k = 0; k < 8; ++k){
					int x = i + dx[k], y = j + dy[k];
					if(x >= 0 && x < r && y >= 0 && y < s && seat[x][y] == '.'){
						++shakes[x][y];
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < s; ++j){
			if(ans < shakes[i][j]){
				ans = shakes[i][j];
			}
		}
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < s; ++j){
			if(seat[i][j] == 'o'){
				for(int k = 0; k < 4; ++k){
					int x = i + dx[k], y = j + dy[k];
					if(x >= 0 && x < r && y >= 0 && y < s && seat[x][y] == 'o'){
						++ans;
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
