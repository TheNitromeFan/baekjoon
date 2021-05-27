#include <cstdio>
#define MAX 101

void flip_coins(char coins[][MAX], int x, int y){
	for(int i = 0; i <= x; ++i){
		for(int j = 0; j <= y; ++j){
			if(coins[i][j] == '0'){
				coins[i][j] = '1';
			}else{
				coins[i][j] = '0';
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char coins[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", coins[i]);
	}
	int cnt = 0;
	for(int i = n - 1; i >= 0; --i){
		for(int j = m - 1; j >= 0; --j){
			if(coins[i][j] == '1'){
				++cnt;
				flip_coins(coins, i, j);
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
