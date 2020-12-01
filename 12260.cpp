#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);
		printf("Case #%d: ", a0);
		double time = 0;
		double rate = 2;
		if(x <= c){
			time = x / rate;
			printf("%.7lf\n", time);
			continue;
		}
		while(true){
			time += c / rate;
			if((x - c) / rate <= x / (rate + f)){
				time += (x - c) / rate;
				break;
			}
			rate += f;
		}
		printf("%.7lf\n", time);
	}
	return 0;
}
