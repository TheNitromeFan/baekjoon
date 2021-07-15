#include <cstdio>
#define MAX 101

bool can_divide(int h, int w, int n, int &x, int &y){
	for(int i = 1; 2 * i - 1 <= h; ++i){
		if(n % i != 0){
			continue;
		}
		int j = n / i;
		if(2 * j - 1 <= w){
			x = i;
			y = j;
			return true;
		}
	}
	return false;
}

int main(){
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);
	int x = -1, y = -1;
	if(can_divide(h, w, n, x, y)){
		char map[MAX][MAX];
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				map[i][j] = '.';
			}
		}
		for(int i = 1, cnt = 1; cnt < x; i += 2, ++cnt){
			for(int j = 0; j < w; ++j){
				map[i][j] = '#';
			}
		}
		for(int j = 1, cnt = 1; cnt < y; j += 2, ++cnt){
			for(int i = 0; i < h; ++i){
				map[i][j] = '#';
			}
		}
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("Impossible\n");
	}
	return 0;
}
