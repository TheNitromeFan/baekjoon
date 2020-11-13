#include <cstdio>

int main(){
	int z;
	scanf("%d", &z);
	for(int i = 0; i < z; ++i){
		double x1, y1, z1, x2, y2, z2;
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2);
		double win = x1 * y2 + y1 * z2 + z1 * x2;
		double lose = x2 * y1 + y2 * z1 + z2 * x1;
		if(win > lose){
			printf("ADAM\n");
		}else if(win < lose){
			printf("GOSIA\n");
		}else{
			printf("=\n");
		}
	}
	return 0;
}
