#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int points = 0;
		for(int i = 0; i < n; ++i){
			int x, y;
			scanf("%d %d", &x, &y);
			for(int p = 10; p > 0; --p){
				if(x * x + y * y <= 20 * 20 * (11 - p) * (11 - p)){
					points += p;
					break;
				}
			}
		}
		printf("%d\n", points);
	}
	return 0;
}
