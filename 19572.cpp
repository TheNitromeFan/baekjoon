#include <cstdio>

int main(){
	int d1, d2, d3;
	scanf("%d %d %d", &d1, &d2, &d3);
	double a = (d1 + d2 - d3) / 2.0, b = (d1 + d3 - d2) / 2.0, c = (d2 + d3 - d1) / 2.0;
	if(a > 0 && b > 0 && c > 0){
		printf("1\n%.1lf %.1lf %.1lf", a, b, c);
	}else{
		printf("-1");
	}
	return 0;
}
