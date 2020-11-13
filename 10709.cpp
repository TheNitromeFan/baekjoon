#include <cstdio>

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	char joi[102][102];
	int time[101][101];
	for(int i = 0; i < h; ++i){
		scanf("%s", joi[i]);
		for(int j = 0; j < w; ++j){
			time[i][j] = -1;
		}
	}
	for(int t = 0; t < w; ++t){
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				if(time[i][j] == -1 && j >= t && joi[i][j-t] == 'c'){
					time[i][j] = t;
				}
			}
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			printf("%d ", time[i][j]);
		}
		printf("\n");
	}
	return 0;
}
