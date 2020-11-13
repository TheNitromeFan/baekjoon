#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int xmin = 100, ymin = 100, xmax = 0, ymax = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d,%d", &x, &y);
		if(x <= xmin){
			xmin = x - 1;
		}
		if(x >= xmax){
			xmax = x + 1;
		}
		if(y <= ymin){
			ymin = y - 1;
		}
		if(y >= ymax){
			ymax = y + 1;
		}
	}
	printf("%d,%d\n%d,%d", xmin, ymin, xmax, ymax);
	return 0;
}
