#include <cstdio>

int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	int area = 0;
	if(x3 >= x2 || x4 <= x1 || y3 >= y2 || y4 <= y1){
		area = (x2 - x1) * (y2 - y1);
	}else if((x3 > x1 && y3 > y1) || (x3 > x1 && y4 < y2) || (x4 < x2 && y3 > y1)
	 || (x4 < x2 && y4 < y2) || (x3 > x1 && x4 < x2) || (y3 > y1 && y4 < y2)){
		area = (x2 - x1) * (y2 - y1);
	}else if(x3 > x1){
		area = (x3 - x1) * (y2 - y1);
	}else if(x4 < x2){
		area = (x2 - x4) * (y2 - y1);
	}else if(y3 > y1){
		area = (x2 - x1) * (y3 - y1);
	}else if(y4 < y2){
		area = (x2 - x1) * (y2 - y4);
	}
	printf("%d", area);
	return 0;
}
