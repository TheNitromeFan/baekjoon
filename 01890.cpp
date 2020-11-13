#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int board[100][100] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &board[i][j]);
		}
	}
	long long ways[100][100] = {};
	ways[0][0] = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(board[i][j] == 0){
				continue;
			}
			if(i + board[i][j] < n){
				ways[i + board[i][j]][j] += ways[i][j];
			}
			if(j + board[i][j] < n){
				ways[i][j + board[i][j]] += ways[i][j];
			}
		}
	}
	printf("%lld", ways[n-1][n-1]);
	return 0;
}
