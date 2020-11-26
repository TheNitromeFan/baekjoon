#include <cstdio>

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	int maxEast = 0, maxNorth = 0;
	for(int i = 0; i < r; ++i){
		int x;
		scanf("%d", &x);
		if(maxEast < x){
			maxEast = x;
		}
	}
	for(int j = 0; j < c; ++j){
		int y;
		scanf("%d", &y);
		if(maxNorth < y){
			maxNorth = y;
		}
	}
	printf("%s", maxEast == maxNorth ? "possible" : "impossible");
	return 0;
}
