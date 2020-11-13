#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n % 4 == 0){
		printf("2");
	}else if(n % 2 == 0){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}
