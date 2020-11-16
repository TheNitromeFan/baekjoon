#include <cstdio>

struct point{
	int x;
	int y;
} p[100];

int main(){
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	int maxArea = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if((p[j].x + p[i].x <= h && p[j].y <= w && p[i].y <= w)
			|| (p[j].x + p[i].y <= h && p[j].y <= w && p[i].x <= w)
			|| (p[j].y + p[i].x <= h && p[j].x <= w && p[i].y <= w)
			|| (p[j].y + p[i].y <= h && p[j].x <= w && p[i].x <= w)
			|| (p[j].x + p[i].x <= w && p[j].y <= h && p[i].y <= h)
			|| (p[j].x + p[i].y <= w && p[j].y <= h && p[i].x <= h)
			|| (p[j].y + p[i].x <= w && p[j].x <= h && p[i].y <= h)
			|| (p[j].y + p[i].y <= w && p[j].x <= h && p[i].x <= h)){
				int area = p[j].x * p[j].y + p[i].x * p[i].y;
				if(maxArea < area){
					maxArea = area;
				}
			}
		}
	}
	printf("%d", maxArea);
	return 0;
}
