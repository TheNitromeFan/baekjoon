#include <cstdio>
#include <cmath>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, (int)(cbrt(b)) - (int)cbrt(a - 1));
	}
	return 0;
}
