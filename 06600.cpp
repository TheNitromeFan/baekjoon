#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main(){
	double x1, y1, x2, y2, x3, y3;
	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6){
		double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		double b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		double c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
		printf("%.2lf\n", 2 * PI * a * b * c / sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c)));
	}
	return 0;
}
