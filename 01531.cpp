#include <cstdio>

int main(){
	int board[101][101] = {};
	int n, m;
	scanf("%d %d", &n, &m);
	for(int a0 = 0; a0 < n; ++a0){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int i = x1; i <= x2; ++i){
			for(int j = y1; j <= y2; ++j){
				++board[i][j];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= 100; ++i){
		for(int j = 1; j <= 100; ++j){
			if(board[i][j] > m){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
