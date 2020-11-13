#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int x, w;
		scanf("%d %d", &x, &w);
		int bounces = 0;
		while((x << bounces) < w){
			++bounces;
		}
		printf("%d\n", bounces);
	}
	return 0;
}
