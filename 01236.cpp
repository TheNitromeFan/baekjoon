#include <cstdio>

bool any_row(char castle[][51], int m, int row){
	for(int j = 0; j < m; ++j){
		if(castle[row][j] == 'X'){
			return true;
		}
	}
	return false;
}

bool any_col(char castle[][51], int n, int col){
	for(int i = 0; i < n; ++i){
		if(castle[i][col] == 'X'){
			return true;
		}
	}
	return false;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char castle[51][51];
	for(int i = 0; i < n; ++i){
		scanf("%s", castle[i]);
	}
	int rows = 0;
	for(int i = 0; i < n; ++i){
		if(!any_row(castle, m, i)){
			++rows;
		}
	}
	int cols = 0;
	for(int j = 0; j < m; ++j){
		if(!any_col(castle, n, j)){
			++cols;
		}
	}
	printf("%d", rows > cols ? rows : cols);
	return 0;
}
