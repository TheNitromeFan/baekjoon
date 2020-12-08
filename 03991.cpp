#include <cstdio>

int main(){
	int h, w, c;
	scanf("%d %d %d", &h, &w, &c);
	int bubbles[11];
	for(int i = 1; i <= c; ++i){
		scanf("%d", &bubbles[i]);
	}
	int a[10][10];
	int idx = 1;
	for(int i = 0; i < h; ++i){
		if(i % 2 == 0){
			for(int j = 0; j < w; ++j){
				while(idx <= c && bubbles[idx] == 0){
					++idx;
				}
				a[i][j] = idx;
				--bubbles[idx];
			}
		}else{
			for(int j = w - 1; j >= 0; --j){
				while(idx <= c && bubbles[idx] == 0){
					++idx;
				}
				a[i][j] = idx;
				--bubbles[idx];
			}
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
