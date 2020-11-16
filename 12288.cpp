#include <cstdio>
#include <cmath>

int main(){
	int t;
	scanf("%d", &t);
	double g = 9.8;
	for(int i = 1; i <= t; ++i){
		int v, d;
		scanf("%d %d", &v, &d);
		printf("Case #%d: %.9lf\n", i, asin(g * d / v / v) * 180 / acos(-1) / 2);
	}
	return 0;
}
