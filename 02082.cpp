#include <cstdio>

char digits[10][5][4] = {{"###", "#.#", "#.#", "#.#", "###"},
						 {"..#", "..#", "..#", "..#", "..#"},
						 {"###", "..#", "###", "#..", "###"},
						 {"###", "..#", "###", "..#", "###"},
						 {"#.#", "#.#", "###", "..#", "..#"},
						 {"###", "#..", "###", "..#", "###"},
						 {"###", "#..", "###", "#.#", "###"},
						 {"###", "..#", "..#", "..#", "..#"},
						 {"###", "#.#", "###", "#.#", "###"},
						 {"###", "#.#", "###", "..#", "###"}};

bool compare_digit(char display[5][4], int digit){
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 3; ++j){
			if(display[i][j] == '#' && digits[digit][i][j] == '.'){
				return false;
			}
		}
	}
	return true;
}

int minimal_digit(char display[5][4]){
	for(int digit = 0; digit <= 9; ++digit){
		if(compare_digit(display, digit)){
			return digit;
		}
	}
	return -1;
}

int main(){
	char time[4][5][4];
	for(int j = 0; j < 5; ++j){
		for(int i = 0; i < 4; ++i){
			scanf("%s", time[i][j]);
		}
	}
	for(int i = 0; i < 2; ++i){
		printf("%d", minimal_digit(time[i]));
	}
	printf(":");
	for(int i = 2; i < 4; ++i){
		printf("%d", minimal_digit(time[i]));
	}
	return 0;
}
