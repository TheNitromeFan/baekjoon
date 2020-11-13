#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int sum = 0, min = 200;
		for(int j = 0; j < 7; ++j){
			int x;
			scanf("%d", &x);
			if(x % 2 == 0){
				sum += x;
				if(x < min){
					min = x;
				}
			}
		}
		printf("%d %d\n", sum, min);
	}
	return 0;
}
