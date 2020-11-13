#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	while(true){
		printf("%d ", n);
		if(n == 1){
			break;
		}else if(n % 2 == 1){
			n = 3 * n + 1;
		}else{
			n /= 2;
		}
	}
	return 0;
}
