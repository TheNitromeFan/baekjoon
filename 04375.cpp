#include <cstdio>

int main(){
	int n;
	while(scanf("%d", &n) == 1){
		int pow10 = 1;
		int ones = 0;
		do{
			pow10 *= 10;
			pow10 %= 9 * n;
			++ones;
		}while(pow10 != 1);
		printf("%d\n", ones);
	}
	return 0;
}
