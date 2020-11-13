#include <cstdio>

int main(){
	int max = 0, x = 0, y = 0;
	for(int i = 1; i <= 9; ++i){
		for(int j = 1; j <= 9; ++j){
			int t;
			scanf("%d", &t);
			if(max < t){
				max = t;
				x = i;
				y = j;
			}
		}
	}
	printf("%d\n%d %d", max, x, y);
	return 0;
}
