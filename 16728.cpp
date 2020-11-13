#include <cstdio>

int score(int x, int y){
	for(int i = 0; i < 10; ++i){
		if(x * x + y * y <= ((2 * i + 1) * 10) * ((2 * i + 1) * 10)){
			return 10 - i;
		}
	}
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	int points = 0;
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		points += score(x, y);
	}
	printf("%d", points);
	return 0;
}
