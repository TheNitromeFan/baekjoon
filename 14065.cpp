#include <cstdio>

int main(){
	double mpg;
	scanf("%lf", &mpg);
	printf("%lf", 3.785411784 * 100000 / 1609.344 / mpg);
	return 0;
}
