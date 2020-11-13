#include <cstdio>

char board[25][25];

bool visited[25][25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool selected[26];

void backtrack(int r, int c, int x, int y, int cnt, int &max){
	if(visited[x][y] || selected[board[x][y] - 'A']){
		return;
	}
	visited[x][y] = true;
	selected[board[x][y] - 'A'] = true;
	++cnt;
	if(cnt > max){
		max = cnt;
	}
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c){
			backtrack(r, c, nx, ny, cnt, max);
		}
	}
	visited[x][y] = false;
	selected[board[x][y] - 'A'] = false;
	--cnt;
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; ++i){
		scanf("%s", board[i]);
	}
	int max = 0;
	backtrack(r, c, 0, 0, 0, max);
	printf("%d", max);
	return 0;
}
