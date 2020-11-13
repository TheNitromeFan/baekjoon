#include <cstdio>
#include <cmath>

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	if(x == y){
		printf("0");
		return 0;
	}
	int n = (int)sqrt(y - x);
	int ans;
	if(n * n + x == y){
		ans = 2 * n - 1;
	}else if(n * n + x + n >= y){
		ans = 2 * n;
	}else{
		ans = 2 * n + 1;
	}
	printf("%d", ans);
	return 0;
}
