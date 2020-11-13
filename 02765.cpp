#include <cstdio>
#include <cmath>
#define PI acos(-1)

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		double diam, time;
		int rev;
		scanf("%lf %d %lf", &diam, &rev, &time);
		if(rev == 0){
			break;
		}
		double dist = PI * diam * rev / 63360;
		double speed = dist * 3600 / time;
		printf("Trip #%d: %.2f %.2f\n", cnt, round(dist * 100) / 100, round(speed * 100) / 100);
	}
	return 0;
}
