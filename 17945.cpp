#include <cstdio>
#include <cmath>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int x1 = -a - (int)sqrt(a * a - b), x2 = -a + (int)sqrt(a * a - b);
	if(x1 == x2){
		printf("%d", x1);
	}else{
		printf("%d %d", x1, x2);
	}
	return 0;
}
