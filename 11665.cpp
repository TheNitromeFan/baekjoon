#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int maxx1 = 0, maxy1 = 0, maxz1 = 0, minx2 = 1001, miny2 = 1001, minz2 = 1001;
	for(int i = 0; i < n; ++i){
		int x1, y1, z1, x2, y2, z2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
		if(maxx1 < x1){
			maxx1 = x1;
		}
		if(maxy1 < y1){
			maxy1 = y1;
		}
		if(maxz1 < z1){
			maxz1 = z1;
		}
		if(minx2 > x2){
			minx2 = x2;
		}
		if(miny2 > y2){
			miny2 = y2;
		}
		if(minz2 > z2){
			minz2 = z2;
		}
	}
	if(minx2 > maxx1 && miny2 > maxy1 && minz2 > maxz1){
		printf("%d", (minx2 - maxx1) * (miny2 - maxy1) * (minz2 - maxz1));
	}else{
		printf("0");
	}
	return 0;
}
