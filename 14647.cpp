#include <cstdio>
#define MAX 500

int nines(int n){
	int ret = 0;
	while(n){
		if(n % 10 == 9){
			++ret;
		}
		n /= 10;
	}
	return ret;
}

int max_row_or_col(int board[][MAX], int n, int m){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		int sum = 0;
		for(int j = 0; j < m; ++j){
			sum += board[i][j];
		}
		if(sum > ret){
			ret = sum;
		}
	}
	for(int j = 0; j < m; ++j){
		int sum = 0;
		for(int i = 0; i < n; ++i){
			sum += board[i][j];
		}
		if(sum > ret){
			ret = sum;
		}
	}
	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int board[MAX][MAX] = {};
	int sum = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int x;
			scanf("%d", &x);
			board[i][j] = nines(x);
			sum += board[i][j];
		}
	}
	printf("%d", sum - max_row_or_col(board, n, m));
	return 0;
}
