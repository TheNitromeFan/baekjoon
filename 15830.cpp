#include <cstdio>
#include <cmath>

int main(){
	double v, w, d;
	scanf("%lf %lf %lf", &v, &w, &d);
	printf("%d", (int)(log(1 + 9 * v * v * d / 80.0 / w / w) / (log(25 / 16.0))));
	return 0;
}
