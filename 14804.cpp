#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int d, n;
		scanf("%d %d", &d, &n);
		double maxSpeed = 1000000001;
		for(int i = 0; i < n; ++i){
			int ki, si;
			scanf("%d %d", &ki, &si);
			double limitSpeed = (double)d / (d - ki) * si;
			if(maxSpeed > limitSpeed){
				maxSpeed = limitSpeed;
			}
		}
		printf("Case #%d: %.6lf\n", a0, maxSpeed);
	}
	return 0;
}
