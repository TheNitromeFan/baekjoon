#include <cstdio>
#define MAX 100

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == -1){
			break;
		}
		char board[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", board[i]);
		}
		long long ways[MAX][MAX] = {};
		ways[0][0] = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(board[i][j] == '0'){
					continue;
				}
				if(i + board[i][j] - '0' < n){
					ways[i + board[i][j] - '0'][j] += ways[i][j];
				}
				if(j + board[i][j] - '0' < n){
					ways[i][j + board[i][j] - '0'] += ways[i][j];
				}
			}
		}
		printf("%lld\n", ways[n-1][n-1]);
	}
	return 0;
}
