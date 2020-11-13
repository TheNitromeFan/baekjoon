#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main(){
	while(true){
		double x, y;
		scanf("%lf %lf", &x, &y);
		if(x == 0 && y == 0){
			break;
		}
		double area = PI / 2 * (x * x + y * y);
		printf("The property will be flooded in hour %d.\n", (int)(area / 50) + 1);
	}
	return 0;
}
