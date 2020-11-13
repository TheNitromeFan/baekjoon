#include <cstdio>
#include <cmath>

int main(){
	while(true){
		double x;
		scanf("%lf", &x);
		if(x == -1){
			break;
		}
		double y = x * 0.167;
		printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n", round(x * 100) / 100, round(y * 100) / 100);
	}
	return 0;
}
