#include <cstdio>

int main(){
	int x, k;
	scanf("%d %d", &x, &k);
	int snow = 0;
	if(7 * k <= x){
		snow = 7000 * k;
	}else if(7 * k <= 2 * x){
		snow = 3500 * k;
	}else if(7 * k <= 4 * x){
		snow = 1750 * k;
	}
	printf("%d", snow);
	return 0;
}
