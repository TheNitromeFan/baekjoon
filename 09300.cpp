#include <cstdio>
#include <cmath>
#define PI (acos(-1))

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		double h, theta;
		scanf("%lf %lf", &h, &theta);
		if(theta > 0){
			printf("Case %d: %.8lf\n", i, fabs(h * tan((90 - theta) * PI / 180) - h));
		}else{
			printf("Case %d: Infinity\n", i);
		}
		
	}
	return 0;
}
