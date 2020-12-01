#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int r, c, w;
		scanf("%d %d %d", &r, &c, &w);
		printf("Case #%d: %d\n", a0, r * (c / w) + w - 1 + (c % w != 0));
	}
	return 0;
}
