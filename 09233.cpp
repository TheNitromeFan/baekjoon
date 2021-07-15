#include <cstdio>
#define MAX 7

bool all_zero(int connect[][MAX], int r, int c){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(connect[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}

bool valid(int connect[][MAX], int r, int c, int x){
	if(x == r * (c - 1) + (r - 1) * c){
		return all_zero(connect, r, c);
	}
	if(valid(connect, r, c, x + 1)){
		return true;
	}
	if(x < r * (c - 1)){
		int i = x / (c - 1), j = x % (c - 1);
		if(connect[i][j] > 0 && connect[i][j + 1] > 0){
			--connect[i][j];
			--connect[i][j + 1];
			if(valid(connect, r, c, x + 1)){
				return true;
			}
			++connect[i][j];
			++connect[i][j + 1];
		}
	}else{
		int i = (x - r * (c - 1)) / c, j = (x - r * (c - 1)) % c;
		if(connect[i][j] > 0 && connect[i + 1][j] > 0){
			--connect[i][j];
			--connect[i + 1][j];
			if(valid(connect, r, c, x + 1)){
				return true;
			}
			++connect[i][j];
			++connect[i + 1][j];
		}
	}
	return false;
}

int main(){
	int t = 0;
	while(true){
		int r, c;
		scanf("%d %d", &r, &c);
		if(r == 0 && c == 0){
			break;
		}
		++t;
		char map[MAX][MAX];
		for(int i = 0; i < r; ++i){
			scanf("%s", map[i]);
		}
		int connect[MAX][MAX] = {};
		for(int x = 0; x < r; ++x){
			for(int y = 0; y < c; ++y){
				switch(map[x][y]){
					case 'C':
						connect[x][y] = 4;
						break;
					case 'N':
						connect[x][y] = 3;
						break;
					case 'O':
						connect[x][y] = 2;
						break;
					case 'H':
						connect[x][y] = 1;
						break;
				}
			}
		}
		printf("Molecule %d is %s.\n", t, (valid(connect, r, c, 0) ? "valid" : "invalid"));
	}
	return 0;
}
