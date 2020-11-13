#include <cstdio>
#include <algorithm>

int main(){
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double x = a * b / c, y = a * c / b;
	printf("%d", static_cast<int>(std::max(x, y)));
	return 0;
}
