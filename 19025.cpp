#include <cstdio>

bool equals(char a[][22], int col1, int col2, char time[][5]){
	for(int i = 0; i < 7; ++i){
		for(int j = col1, k = 0; j < col2; ++j, ++k){
			if(a[i][j] != time[i][k]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	char digits[10][7][5] = {{".XX.", "X..X", "X..X", "....", "X..X", "X..X", ".XX."},
							 {"....", "...X", "...X", "....", "...X", "...X", "...."},
							 {".XX.", "...X", "...X", ".XX.", "X...", "X...", ".XX."},
							 {".XX.", "...X", "...X", ".XX.", "...X", "...X", ".XX."},
							 {"....", "X..X", "X..X", ".XX.", "...X", "...X", "...."},
							 {".XX.", "X...", "X...", ".XX.", "...X", "...X", ".XX."},
							 {".XX.", "X...", "X...", ".XX.", "X..X", "X..X", ".XX."},
							 {".XX.", "...X", "...X", "....", "...X", "...X", "...."},
							 {".XX.", "X..X", "X..X", ".XX.", "X..X", "X..X", ".XX."},
							 {".XX.", "X..X", "X..X", ".XX.", "...X", "...X", ".XX."}};
	for(int a0 = 0; a0 < t; ++a0){
		char clock[7][22];
		for(int i = 0; i < 7; ++i){
			scanf("%s", clock[i]);
		}
		for(int digit = 0; digit < 10; ++digit){
			if(equals(clock, 0, 4, digits[digit])){
				printf("%d", digit);
				break;
			}
		}
 		for(int digit = 0; digit < 10; ++digit){
			if(equals(clock, 5, 9, digits[digit])){
				printf("%d", digit);
				break;
			}
		}
		printf(":");
		for(int digit = 0; digit < 10; ++digit){
			if(equals(clock, 12, 16, digits[digit])){
				printf("%d", digit);
				break;
			}
		}
		for(int digit = 0; digit < 10; ++digit){
			if(equals(clock, 17, 21, digits[digit])){
				printf("%d", digit);
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
