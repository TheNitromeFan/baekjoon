#include <cstdio>

void flip(char bulbs[][11], int x, int y){
	bulbs[x][y] = 'O' - bulbs[x][y] + '#';
}

void press(char bulbs[][11], int dx[5], int dy[5], int x, int y){
	for(int i = 0; i < 5; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < 10 && ny >= 0 && ny < 10){
			flip(bulbs, nx, ny);
		}
	}
}

int press_count(char bulbs[][11], int dx[5], int dy[5], int start){
	int ret = 0;
	for(int j = 0; j < 10; ++j){
		if(start % 2 == 1){
			press(bulbs, dx, dy, 0, j);
			++ret;
		}
		start /= 2;
	}
	for(int i = 1; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			if(bulbs[i - 1][j] == 'O'){
				press(bulbs, dx, dy, i, j);
				++ret;
			}
		}
	}
	for(int j = 0; j < 10; ++j){
		if(bulbs[9][j] == 'O'){
			return -1;
		}
	}
	return ret;
}

int main(){
	char bulbs[10][11];
	for(int i = 0; i < 10; ++i){
		scanf("%s", bulbs[i]);
	}
	int dx[5] = {0, 1, -1, 0, 0};
	int dy[5] = {0, 0, 0, 1, -1};
	int min_presses = -1;
	char bulbs_copy[10][11];
	for(int start = 0; start < (1 << 10); ++start){
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < 10; ++j){
				bulbs_copy[i][j] = bulbs[i][j];
			}
		}
		int presses = press_count(bulbs_copy, dx, dy, start);
		if(presses != -1 && (min_presses == -1 || min_presses > presses)){
			min_presses = presses;
		}
	}
	printf("%d\n", min_presses);
	return 0;
}
