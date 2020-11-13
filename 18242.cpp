#include <cstdio>
#define MAX (100 + 1)

int row_count(char map[][MAX], int n, int m, int row){
	int ret = 0;
	for(int j = 0; j < m; ++j){
		if(map[row][j] == '#'){
			++ret;
		}
	}
	return ret;
}

int column_count(char map[][MAX], int n, int m, int column){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		if(map[i][column] == '#'){
			++ret;
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char rect[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", rect[i]);
	}
	int up = row_count(rect, n, m, 0), down = row_count(rect, n, m, n - 1), 
		left = column_count(rect, n, m, 0), right = column_count(rect, n, m, m - 1);
	for(int i = 0; i < n - 1; ++i){
		int top = row_count(rect, n, m, i), bottom = row_count(rect, n, m, i + 1);
		if(top == 0 && bottom != 0){
			up = bottom;
		}else if(top != 0 && bottom == 0){
			down = top;
		}
	}
	for(int j = 0; j < m - 1; ++j){
		int front = column_count(rect, n, m, j), back = column_count(rect, n, m, j + 1);
		if(front == 0 && back != 0){
			left = back;
		}else if(front != 0 && back == 0){
			right = front;
		}
	}
	if(up < down){
		printf("UP");
	}else if(up > down){
		printf("DOWN");
	}else if(left < right){
		printf("LEFT");
	}else if(left > right){
		printf("RIGHT");
	}
	return 0;
}
