#include <cstdio>
#include <algorithm>

using std::max;
using std::min;

int overlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int x0 = max(x1, x3), y0 = max(y1, y3), x = min(x2, x4), y = min(y2, y4);
	if(x > x0 && y > y0){
		return (x - x0) * (y - y0);
	}
	return 0;
}

int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d",
		&x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5, &x6, &y6);
	printf("%d", (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3)
		- overlap(x1, y1, x2, y2, x5, y5, x6, y6) - overlap(x3, y3, x4, y4, x5, y5, x6, y6));
	return 0;
}
