#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int v, d;
		scanf("%d %d", &v, &d);
		printf("Case #%d: %.7lf\n", i, asin(9.8 * d / v / v) * 90 / PI);
	}
	return 0;
}
