#include <cstdio>

int main(){
	int ax, ay, az, bx, by, bz, cx, cy, cz;
	scanf("%d %d %d %d %d %d", &ax, &ay, &az, &cx, &cy, &cz);
	bx = cx - az;
	by = cy / ay;
	bz = cz - ax;
	printf("%d %d %d", bx, by, bz);
	return 0;
}
