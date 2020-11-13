#include <cstdio>

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if((a + b) % 2 == (c + d) % 2){
		printf("black");
	}else{
		printf("white");
	}
	return 0;
}
