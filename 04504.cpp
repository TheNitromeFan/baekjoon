#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int value;
	while(1){
		scanf("%d", &value);
		if(value == 0){
			break;
		}
		if(value % n == 0){
			printf("%d is a multiple of %d.\n", value, n);
		}else{
			printf("%d is NOT a multiple of %d.\n", value, n);
		}
	}
	return 0;
}
