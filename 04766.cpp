#include <cstdio>

int main(){
	double prev, cur;
	scanf("%lf %lf", &prev, &cur);
	do{
		printf("%.2f\n", cur - prev);
		prev = cur;
		scanf("%lf", &cur);
	}while(cur != 999);
	return 0;
}
