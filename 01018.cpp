#include <cstdio>
#include <algorithm>

using namespace std;

const char color[3] = "BW";

int repaint(char b[][51], int startrow, int startcol){
	int cnt = 0;
	for(int i = startrow; i < startrow+8; ++i){
		for(int j = startcol; j < startcol+8; ++j){
			if(b[i][j] != color[(i+j)%2]){
				++cnt;
			}
			else{
			}
		}
	}
	return min(cnt, 64-cnt);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char board[51][51];
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	int ans = 32;
	for(int i = 0; i <= n-8; ++i){
		for(int j = 0; j <= m-8; ++j){
			int tmp = repaint(board, i, j);
			if(tmp < ans){
				ans = tmp;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
