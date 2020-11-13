#include <cstdio>
#include <cmath>

int main(){
	int x1, y1, x2, y2, x3, y3;
	double r;
	scanf("%d %d %d %d %d %d %lf", &x1, &y1, &x2, &y2, &x3, &y3, &r);
	double a2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	double b2 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
	double c2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
	double inr = sqrt(4 * a2 * b2 - (a2 + b2 - c2) * (a2 + b2 - c2)) / (2 * (sqrt(a2) + sqrt(b2) + sqrt(c2)));
	printf("%lf", 100 * (inr - r) / r);
	return 0;
}
