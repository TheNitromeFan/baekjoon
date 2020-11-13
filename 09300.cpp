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
		printf("Case %d: %f\n", i, abs(h * tan((90 - theta) * PI / 180) - h));
	}
	return 0;
}
