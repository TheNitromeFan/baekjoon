#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ones = 0;
	if(n == 0){
		n = 1;
	}
	if(n > 0){
		while(n != 0){
			++ones;
			n /= 2;
		}
	}else{
		ones = 32;
	}
	printf("%d", ones);
	return 0;
}
