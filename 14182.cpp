#include <cstdio>

int main(){
	while(true){
		int x;
		scanf("%d", &x);
		if(x == 0){
			break;
		}
		if(x > 5000000){
			x /= 5;
			x *= 4;
		}else if(x > 1000000){
			x /= 10;
			x *= 9;
		}
		printf("%d\n", x);
	}
	return 0;
}
