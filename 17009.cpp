#include <cstdio>

int main(){
	int a[3], b[3];
	for(int i = 0; i < 3; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < 3; ++i){
		scanf("%d", &b[i]);
	}
	int apple = 3 * a[0] + 2 * a[1] + a[2], banana = 3 * b[0] + 2 * b[1] + b[2];
	if(apple > banana){
		printf("A");
	}else if(apple < banana){
		printf("B");
	}else{
		printf("T");
	}
	return 0;
}
