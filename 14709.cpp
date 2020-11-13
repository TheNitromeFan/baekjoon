#include <cstdio>

bool fox(bool touch[][6]){
	for(int i = 1; i <= 5; ++i){
		for(int j = 1; j < i; ++j){
			if((i == 3 && j == 1) || (i == 4 && j == 1) || (i == 4 && j == 3)){
				if(!touch[i][j]){
					return false;
				}
			}else{
				if(touch[i][j]){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	bool touch[6][6] = {};
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		touch[x][y] = true;
		touch[y][x] = true;
	}
	printf("%s", fox(touch) ? "Wa-pa-pa-pa-pa-pa-pow!" : "Woof-meow-tweet-squeek");
}
