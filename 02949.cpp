#include <cstdio>
#include <algorithm>
#define MAX 50

using std::swap;

void array_copy(char src[][MAX], char dest[][MAX], int &r, int &c){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			dest[i][j] = src[i][j];
		}
	}
}

void rotate_clockwise_90(char a[][MAX], int &r, int &c){
	char b[MAX][MAX];
	for(int i = 0; i < c; ++i){
		for(int j = 0; j < r; ++j){
			b[i][j] = a[r - 1 - j][i];
		}
	}
	int tmp = r;
	r = c;
	c = tmp;
	array_copy(b, a, r, c);
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char a[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", a[i]);
	}
	int angle;
	scanf("%d", &angle);
	while(angle >= 90){
		rotate_clockwise_90(a, r, c);
		angle -= 90;
	}
	if(angle == 0){
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}else{
		for(int row = 0; row < r - 1; ++row){
			for(int k = 0; k < r - 2 - row; ++k){
				printf(" ");
			}
			for(int i = row, j = 0; i >= 0 && j < c; --i, ++j){
				printf(" %c", a[i][j]);
			}
			printf("\n");
		}
		for(int i = r - 1, j = 0; i >= 0 && j < c; --i, ++j){
			printf("%c", a[i][j]);
			if(i - 1 >= 0 && j + 1 < c){
				printf(" ");
			}
		}
		printf("\n");
		for(int row = r; row < r + c - 1; ++row){
			for(int k = 0; k < row - r; ++k){
				printf(" ");
			}
			for(int i = r - 1, j = row - r + 1; i >= 0 && j < c; --i, ++j){
				printf(" %c", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
