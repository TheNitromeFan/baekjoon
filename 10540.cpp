#include <cstdio>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);
	int x, y;
	scanf("%d %d", &x, &y);
	int minx = x, maxx = x, miny = y, maxy = y;
	for(int i = 1; i < n; ++i){
		scanf("%d %d", &x, &y);
		if(minx > x){
			minx = x;
		}
		if(maxx < x){
			maxx = x;
		}
		if(miny > y){
			miny = y;
		}
		if(maxy < y){
			maxy = y;
		}
	}
	int side = std::max(maxx - minx, maxy - miny);
	printf("%d", side * side);
	return 0;
}
