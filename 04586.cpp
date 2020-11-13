#include <cstdio>
#define MAX (64 + 1)

void recolor(char image[][MAX], int thres, int n, int x, int y){
	int sz = n * n;
	int black = 0;
	for(int i = x; i < x + n; ++i){
		for(int j = y; j < y + n; ++j){
			if(image[i][j] == '1'){
				++black;
			}
		}
	}
	int white = sz - black;
	if(black * 100 >= sz * thres){
		for(int i = x; i < x + n; ++i){
			for(int j = y; j < y + n; ++j){
				image[i][j] = '1';
			}
		}
	}else if(white * 100 >= sz * thres){
		for(int i = x; i < x + n; ++i){
			for(int j = y; j < y + n; ++j){
				image[i][j] = '0';
			}
		}
	}else{
		recolor(image, thres, n / 2, x, y);
		recolor(image, thres, n / 2, x, y + n / 2);
		recolor(image, thres, n / 2, x + n / 2, y);
		recolor(image, thres, n / 2, x + n / 2, y + n / 2);
	}
}

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int t;
		scanf("%d", &t);
		char image[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", image[i]);
		}
		recolor(image, t, n, 0, 0);
		printf("Image %d:\n", cnt);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%c", image[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
