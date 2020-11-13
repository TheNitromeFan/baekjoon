#include <cstdio>
#include <cmath>

int main(){
	double a0, e, a;
	while(scanf("%lf %lf %lf", &a0, &e, &a) == 3){
		printf("%d\n", (int)ceil(log(a / a0) / log(1 + e / 100)));
	}
	return 0;
}
