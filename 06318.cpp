#include <cstdio>
#include <cstdlib>

int main(){
	int test = 1;
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int bricks[50];
		int sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &bricks[i]);
			sum += bricks[i];
		}
		int height = sum / n;
		int moves = 0;
		for(int i = 0; i < n; ++i){
			moves += abs(height - bricks[i]);
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", test, moves / 2);
		++test;
	}
	return 0;
}
