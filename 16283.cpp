#include <cstdio>
#include <cstdlib>

int main(){
	int a, b, n, w;
	scanf("%d %d %d %d", &a, &b, &n, &w);
	if(a == b && n == 2 && w / a == 2){
		printf("1 1");
		return 0;
	}
	else if(a == b || abs(w - n * b) % abs(a - b) != 0){
		printf("-1");
		return 0;
	}
	int x = (w - n * b) / (a - b), y = (n * a - w) / (a - b);
	if(x <= 0 || y <= 0){
		printf("-1");
	}else{
		printf("%d %d", x, y);
	}
	return 0;
}
