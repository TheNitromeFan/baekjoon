#include <cstdio>
#include <cmath>

int main(){
	while(true){
		int d, s1, s2;
		scanf("%d %d %d", &d, &s1, &s2);
		if(d == 0 && s1 == 0 && s2 == 0){
			break;
		}
		double time = d * 60.0 * 60 / s1 - d * 60.0 * 60 / s2;
		int s = (int)round(time);
		int h = s / 60 / 60, m = s / 60 % 60;
		s %= 60;
		printf("%01d:%02d:%02d\n", h, m, s);
	}
	return 0;
}
