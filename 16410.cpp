#include <cstdio>
#include <cmath>

double dist(int x1, int y1, int x2, int y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(){
	int x, y, x1, y1, x2, y2;
	scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);
	double d = 0;
	if(x > x2 && y > y2){
		d = dist(x, y, x2, y2);
	}else if(x > x2 && y < y1){
		d = dist(x, y, x2, y1);
	}else if(x < x1 && y > y2){
		d = dist(x, y, x1, y2);
	}else if(x < x1 && y < y1){
		d = dist(x, y, x1, y1);
	}else if(x > x2){
		d = x - x2;
	}else if(x < x1){
		d = x1 - x;
	}else if(y > y2){
		d = y - y2;
	}else if(y < y1){
		d = y1 - y;
	}
	printf("%.6f", d);
	return 0;
}
