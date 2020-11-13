#include <cstdio>

char a[(1 << 10) - 1][(1 << 11) - 2];

void draw(int level, int h, int w, int x, int y){
	if(level == 0){
		return;
	}
	int left = x, right = x + w;
	int mid = (left + right) / 2;
	if(level % 2 == 1){
		int innerLeft = mid, innerRight = mid;
		for(int i = y; i < y + h; ++i){
			for(int j = innerLeft; j <= innerRight; ++j){
				if(i == y || i == y + h - 1 || j == innerLeft || j == innerRight){
					a[i][j] = '*';
				}else{
					a[i][j] = ' ';
				}
			}
			--innerLeft;
			++innerRight;
		}
	}else{
		int innerLeft = left, innerRight = right;
		for(int i = y; i < y + h; ++i){
			for(int j = innerLeft; j < innerRight; ++j){
				if(i == y || i == y + h - 1 || j == innerLeft || j == innerRight - 1){
					a[i][j] = '*';
				}else{
					a[i][j] = ' ';
				}
			}
			++innerLeft;
			--innerRight;
		}
	}
	int dx = x + (1 << (level - 1));
	if(level % 2 == 1){
		draw(level - 1, h / 2, w - (1 << level), dx, y + h / 2);
	}else{
		draw(level - 1, h / 2, w - (1 << level), dx, y + 1);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int h = (1 << n) - 1, w = (1 << (n + 1)) - 3;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			a[i][j] = ' ';
		}
	}
	draw(n, h, w, 0, 0);
	if(n % 2 == 0){
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w - i; ++j){
				printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}else{
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w / 2 + i + 1; ++j){
				printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
