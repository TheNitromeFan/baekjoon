#include <cstdio>
#include <cmath>

int main(){
	while(true){
		double te, tr;
		scanf("%lf %lf", &te, &tr);
		if(te == 0 && tr == 0){
			break;
		}
		printf("%.3f\n", round(sqrt(1 - tr * tr / te / te) * 1000) / 1000);
	}
	return 0;
}
