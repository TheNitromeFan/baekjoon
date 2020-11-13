#include <cstdio>
#include <cmath>

int main(){
	while(true){
		double prevr, prevw;
		scanf("%lf %lf", &prevr, &prevw);
		if(prevr == -1 && prevw == -1){
			break;
		}
		double totr = 0, totw = 0;
		while(true){
			double curr, curw;
			scanf("%lf %lf", &curr, &curw);
			if(curr == 0 && curw == 0){
				break;
			}else if(curw <= prevw){
				totr += curr - prevr;
				totw += prevw - curw;
			}
			prevr = curr;
			prevw = curw;
		}
		printf("%d\n", (int)round(totr * prevw / totw));
	}
	return 0;
}
