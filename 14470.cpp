#include <cstdio>

int main(){
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int ans = 0;
	if(a <= 0 && b >= 0){
		ans = c * (-a) + d + e * b;
	}else if(b < 0){
		ans = c * (b - a);
	}else{
		ans = e * (b - a);
	}
	printf("%d", ans);
	return 0;
}
