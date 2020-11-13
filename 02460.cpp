#include <cstdio>

int main(){
	int current = 0, max = 0;
	for(int i = 0; i < 10; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		current += y - x;
		if(current > max){
			max = current;
		}
	}
	printf("%d", max);
	return 0;
}
