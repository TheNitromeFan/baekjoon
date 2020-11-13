#include <cstdio>
#define MAX (30 + 1)

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool flower_part(char c){
	bool ret = false;
	switch(c){
		case '|':
		case '/':
		case '\\':
		case '-':
		case '@':
			ret = true;
			break;
	}
	return ret;
}

bool bird(char map[][MAX], int n, int m, int x, int y){
	if(x > 0 && (map[x - 1][y] != '.' || map[x - 1][y + 1] != '.'
	|| map[x - 1][y + 2] != '.' || map[x - 1][y + 3] != '.')){
		return false;
	}
	if(x < n - 3 && (map[x + 1][y] != '.' || map[x + 1][y + 1] != '.'
	|| map[x + 1][y + 2] != '.' || map[x + 1][y + 3] != '.')){
		return false;
	}
	if(y > 0 && map[x][y - 1] != '.'){
		return false;
	}
	if(y < m - 4 && map[x][y + 4] != '.'){
		return false;
	}
	return map[x][y] == '/' && map[x][y + 1] == '\\'
	&& map[x][y + 2] == '/' && map[x][y + 3] == '\\';
}

void dfs(char map[][MAX], bool visited[][MAX], int n, int m, int x, int y){
	visited[x][y] = true;
	for(int i = 0; i < 8; ++i){
		int nx = x + dx[i], ny = y + dy[i];
		if(x >= 0 && x < n && y >= 0 && y < m && flower_part(map[nx][ny]) && !visited[nx][ny]){
			dfs(map, visited, n, m, nx, ny);
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int h, w;
		scanf("%d %d", &h, &w);
		char pic[MAX][MAX];
		for(int i = 0; i < h; ++i){
			scanf("%s", pic[i]);
		}
		bool visited[MAX][MAX] = {};
		int f = 0;
		for(int j = 0; j < w; ++j){
			if(flower_part(pic[h - 2][j]) && !visited[h - 2][j]){
				++f;
				dfs(pic, visited, h, w, h - 2, j);
			}
		}
		int b = 0;
		for(int i = 0; i < h - 2; ++i){
			for(int j = 0; j < w - 3; ++j){
				if(!visited[i][j] && bird(pic, h, w, i, j)){
					++b;
				}
			}
		}
		printf("Flowers: %d\nBirds: %d\n", f, b);
	}
	return 0;
}
