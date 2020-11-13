#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		double maxx = -1000, minx = 1000, maxy = -1000, miny = 1000;
		for(int i = 0; i < n; ++i){
			double x, y;
			scanf("%lf %lf", &x, &y);
			if(x > maxx){
				maxx = x;
			}
			if(x < minx){
				minx = x;
			}
			if(y > maxy){
				maxy = y;
			}
			if(y < miny){
				miny = y;
			}
		}
		printf("Case %d: Area %f, Perimeter %f\n", a0, (maxx - minx) * (maxy - miny), 2 * (maxx - minx + maxy - miny));
	}
	return 0;
}
