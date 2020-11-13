#include <cstdio>
#include <cmath>

int main(){
	int c, h, w;
	scanf("%d %d %d", &c, &h, &w);
	printf("%d %d", (int)(c * h / sqrt(h * h + w * w)), (int)(c * w / sqrt(h * h + w * w)));
	return 0;
}
