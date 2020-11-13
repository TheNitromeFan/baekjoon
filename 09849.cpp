#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int maxx1 = -1, minx2 = 10001, maxy1 = -1, miny2 = 10001;
	for(int i = 0; i < n; ++i){
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
		if(maxx1 < x1){
			maxx1 = x1;
		}
		if(minx2 > x2){
			minx2 = x2;
		}
		if(maxy1 < y1){
			maxy1 = y1;
		}
		if(miny2 > y2){
			miny2 = y2;
		}
	}
	if(maxx1 < minx2 && maxy1 < miny2){
		printf("%d", (minx2 - maxx1) * (miny2 - maxy1));
	}else{
		printf("0");
	}
	return 0;
}
