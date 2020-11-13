#include <cstdio>

int main(){
	int w, h, k;
	scanf("%d %d %d", &w, &h, &k);
	int a = w / k, b = h / k;
	if(a <= 0 || b <= 0){
		printf("0");
	}else if(a == 1 && b == 1){
		printf("1");
	}else if(a == 1){
		printf("%d", b);
	}else if(b == 1){
		printf("%d", a);
	}else{
		printf("%d", 2 * (a + b - 2));
	}
	return 0;
}
