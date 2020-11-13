#include <cstdio>

int main(){
	while(true){
		int h, d, f;
		double u;
		scanf("%d %lf %d %d", &h, &u, &d, &f);
		if(h == 0 && u == 0 && d == 0 && f == 0){
			break;
		}
		double height = 0;
		int day = 0;
		double fatigue = u * f / 100.0;
		do{
			++day;
			height += u;
			if(height > h){
				break;
			}
			height -= d;
			u -= fatigue;
			if(u < 0){
				u = 0;
			}
		}while(height >= 0 && height <= h);
		if(height > h){
			printf("success on day %d\n", day);
		}else{
			printf("failure on day %d\n", day);
		}
	}
	return 0;
}
