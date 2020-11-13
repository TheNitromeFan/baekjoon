#include <cstdio>
#define MAX 11

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int u, l, r, d;
	scanf("%d %d %d %d", &u, &l, &r, &d);
	char board[MAX][MAX];
	for(int i = 0; i < m; ++i){
		scanf("%s", board[i]);
	}
	for(int i = 0; i < u + m + d; ++i){
		for(int j = 0; j < l + n + r; ++j){
			if(i >= u && i < u + m && j >= l && j < l + n){
				printf("%c", board[i - u][j - l]);
			}else if((i + j) % 2){
				printf(".");
			}else{
				printf("#");
			}
		}
		printf("\n");
	}
	return 0;
}
