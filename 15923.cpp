#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	int diam = 0;
	int sx, sy;
	scanf("%d %d", &sx, &sy);
	int x = sx, y = sy;
	for(int i = 1; i < n; ++i){
		int nx, ny;
		scanf("%d %d", &nx, &ny);
		diam += abs(nx - x) + abs(ny - y);
		x = nx;
		y = ny;
	}
	diam += abs(x - sx) + abs(y - sy);
	printf("%d", diam);
	return 0;
}
