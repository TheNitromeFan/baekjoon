#include <cstdio>

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int ans = 0;
	if(x > 0 && y > 0){
		ans = 1;
	}else if(y > 0){
		ans = 2;
	}else if(x < 0){
		ans = 3;
	}else{
		ans = 4;
	}
	printf("%d", ans);
	return 0;
}
