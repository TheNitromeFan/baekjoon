#include <cstdio>
#include <cmath>

int main(){
	while(true){
		double eng;
		scanf("%lf", &eng);
		if(eng == 0){
			break;
		}
		double rom = eng * 5280 / 4854;
		double paces = rom * 1000;
		printf("%.2f English miles equals %.2f Roman miles or %d paces.\n",
			round(eng * 100) / 100, round(rom * 100) / 100, (int)round(paces));
	}
	return 0;
}
