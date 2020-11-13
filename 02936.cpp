#include <cstdio>

double area = 250.0 * 250.0 / 2;

int main(){
	double x, y;
	scanf("%lf %lf", &x, &y);
	double a, b;
	if(y == 0 && x <= 125){
		b = area / (250 - x);
		a = 250 - b;
	}else if(y == 0){
		b = area / x;
		a = 0;
	}else if(x == 0 && y <= 125){
		a = area / (250 - y);
		b = 250 - a;
	}else if(x == 0){
		a = area / y;
		b = 0;
	}else if(y < 125){
		a = 0;
		b = 250 - area / x;
	}else{
		a = 250 - area / y;
		b = 0;
	}
	printf("%.2lf %.2lf", a, b);
	return 0;
}
