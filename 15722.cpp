#include <cstdio>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
	int n;
	scanf("%d", &n);
	int x = 0, y = 0;
	int dir = 0;
	int maxx = 0, minx = 0, maxy = 0, miny = 0;
	for(int i = 0; i < n; ++i){
		x += dx[dir];
		y += dy[dir];
		if(x > maxx){
			maxx = x;
			dir = (dir + 1) % 4;
		}else if(x < minx){
			minx = x;
			dir = (dir + 1) % 4;
		}else if(y > maxy){
			maxy = y;
			dir = (dir + 1) % 4;
		}else if(y < miny){
			miny = y;
			dir = (dir + 1) % 4;
		}
	}
	printf("%d %d", x, y);
	return 0;
}
