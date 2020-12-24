#include <cstdio>
#define MAX 101

void shift(char field[][MAX], char map[][MAX], int r, int c, int pos, int col){
	int x1 = 0;
	while(x1 < r && field[x1][col] == '.'){
		++x1;
	}
	if(x1 == r){
		return;
	}
	int x2 = r - 1;
	while(x2 >= 0 && field[x2][col] == '.'){
		--x2;
	}
	for(int i = -x1; i + x2 < r; ++i){
		if(pos - i >= r || pos - i < 0 || field[pos - i][col] == '.'){
			for(int x = 0; x < r; ++x){
				if(field[x][col] == '|'){
					map[x + i][col] = '|';
				}
			}
			return;
		}
	}
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char field[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", field[i]);
	}
	int pos = 0;
	for(int i = 0; i < r; ++i){
		if(field[i][0] == 'L'){
			pos = i;
			break;
		}
	}
	char map[MAX][MAX];
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			map[i][j] = '.';
		}
	}
	map[pos][0] = 'L';
	bool up = true;
	for(int j = 1; j < c; ++j){
		if(pos == 0){
			up = false;
		}else if(pos == r - 1){
			up = true;
		}
		if(up){
			--pos;
		}else{
			++pos;
		}
		map[pos][j] = 'L';
		shift(field, map, r, c, pos, j);
	}
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
