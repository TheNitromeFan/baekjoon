#include <cstdio>
#include <cmath>

int main(){
	int h, p;
	while(scanf("%d %d", &h, &p) == 2){
		double ans = h / (double)p;
		printf("%.2f\n", round(ans * 100) / 100);
	}
	return 0;
}
