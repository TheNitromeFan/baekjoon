#include <cstdio>

int main(){
	int n, m, b;
	scanf("%d %d %d", &n, &m, &b);
	int map[500][500];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int maxHeight = 0;
	int minTime = 2000000001;
	for(int height = 256; height >= 0; --height){
		int blocks = 0;
		int time = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				int delta = height - map[i][j];
				blocks += delta;
				if(delta > 0){
					time += delta;
				}else{
					time -= 2 * delta;
				}
			}
		}
		if(blocks <= b && time < minTime){
			maxHeight = height;
			minTime = time;
		}
	}
	printf("%d %d", minTime, maxHeight);
	return 0;
}
