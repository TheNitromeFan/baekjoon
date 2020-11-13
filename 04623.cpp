#include <cstdio>

int main(){
	while(true){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a == 0 && b == 0 && c == 0 && d == 0){
			break;
		}
		int perc = 100;
		while(!((a * perc <= c * 100 && b * perc <= d * 100)
		|| (a * perc <= d * 100 && b * perc <= c * 100))){
			--perc;
		}
		printf("%d%%\n", perc);
	}
	return 0;
}
