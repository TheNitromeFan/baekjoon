#include <cstdio>
#include <cmath>

int main(){
	char c1, c2;
	while(true){
		scanf(" %c", &c1);
		if(c1 == 'E'){
			break;
		}
		double t = -1, d = -1, h = -1;
		double x, y;
		scanf("%lf %c %lf", &x, &c2, &y);
		switch(c1){
			case 'T':
				t = x;
				break;
			case 'D':
				d = x;
				break;
			case 'H':
				h = x;
				break;
		}
		switch(c2){
			case 'T':
				t = y;
				break;
			case 'D':
				d = y;
				break;
			case 'H':
				h = y;
				break;
		}
		if(t == -1){
			t = h - 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16)))) - 10);
		}else if(h == -1){
			h = t + 0.5555 * (6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16)))) - 10);
		}else{
			d = 1 / (1 / 273.16 - log(((h - t) / 0.5555 + 10) / 6.11) / 5417.7530) - 273.16;
		}
		printf("T %.1f D %.1f H %.1f\n", round(t * 10) / 10, round(d * 10) / 10, round(h * 10) / 10);
	}
	return 0;
}
