#include <cstdio>

int main(){
	int c, n;
	scanf("%d %d", &c, &n);
	int prev;
	scanf("%d", &prev);
	for(int i = 1; i < n; ++i){
		int cur;
		scanf("%d", &cur);
		if(prev < cur){
			int q = c / prev, r = c % prev;
			c = q * cur + r;
		}
		prev = cur;
	}
	printf("%d", c);
	return 0;
}
