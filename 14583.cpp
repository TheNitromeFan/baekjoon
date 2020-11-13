#include <cstdio>
#include <cmath>

int main(){
	double h, w;
	scanf("%lf %lf", &w, &h);
	double d = sqrt(w * w + h * h);
	double x = w * h / (w + d), y = d * h / (w + d);
	double a = sqrt(w * w + x * x) / 2;
	double b = w * y / (2 * a);
	printf("%f %f", a, b);
	return 0;
}
