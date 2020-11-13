#include <cstdio>

static char canvas[3072][6144];

void stars(int level, int x, int y){
	
	for(int i = x; i < x+level; i++){
		for(int j = y; j < y+2*level; j++){
			canvas[i][j] = ' ';
		}
	}
	
	if(level == 3){
		canvas[x][y] = '*';
		canvas[x+1][y] = '*';
		canvas[x+1][y+2] = '*';
		canvas[x+2][y] = '*';
		canvas[x+2][y+1] = '*';
		canvas[x+2][y+2] = '*';
		canvas[x+2][y+3] = '*';
		canvas[x+2][y+4] = '*';
	}else{
		stars(level/2, x, y);
		stars(level/2, x+level/2, y);
		stars(level/2, x+level/2, y+level);
	}
	
}

int main(){
	
	int n;
	scanf("%d", &n);
	stars(n, 0, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1-i; j++){
			printf(" ");
		}
		for(int j = 0; j < 2*i+1; j++){
			printf("%c", canvas[i][j]);
		}
		for(int j = 0; j < n-1-i; j++){
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
