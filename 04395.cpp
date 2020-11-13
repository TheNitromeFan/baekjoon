#include <cstdio>
#include <cmath>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == y){
			printf("0\n");
			continue;
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
		printf("%d\n", ans);
	}
	return 0;
}
