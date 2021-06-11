#include <cstdio>
#include <cstring>
#define MAX 101

int cache[MAX][MAX][MAX];

int dp(char board[][MAX], char word[MAX], int dx[4], int dy[4], int n, int m, int k, int len, int x, int y, int cur){
	if(cur == len){
		return 1;
	}
	if(cache[x][y][cur] != -1){
		return cache[x][y][cur];
	}
	cache[x][y][cur] = 0;
	for(int i = 0; i < 4; ++i){
		for(int c = 1; c <= k; ++c){
			int nx = x + c * dx[i];
			int ny = y + c * dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == word[cur]){
				cache[x][y][cur] += dp(board, word, dx, dy, n, m, k, len, nx, ny, cur + 1);
			}
		}
	}
	return cache[x][y][cur];
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	char board[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", board[i]);
	}
	char word[MAX];
	scanf("%s", word);
	int len = strlen(word);
	memset(cache, -1, sizeof(cache));
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(board[i][j] == word[0]){
				ans += dp(board, word, dx, dy, n, m, k, len, i, j, 1);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
