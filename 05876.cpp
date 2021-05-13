#include <cstdio>
#define MAX 6

bool horseshoe(char map[][MAX], bool visited[][MAX], int dx[4], int dy[4], int n, int len, int steps, int x, int y){
	if(visited[x][y]){
		return false;
	}else if(steps == 2 * len){
		return true;
	}
	visited[x][y] = true;
	if(steps >= len){
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == ')'
			&& horseshoe(map, visited, dx, dy, n, len, steps + 1, nx, ny)){
				return true;
			}
		}
	}else{
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == '('
			&& horseshoe(map, visited, dx, dy, n, len, steps + 1, nx, ny)){
				return true;
			}
		}
	}
	visited[x][y] = false;
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	if(map[0][0] == ')'){
		printf("0");
		return 0;
	}
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int ans = 0;
	for(int len = 1; len <= 13; ++len){
		bool visited[MAX][MAX] = {};
		if(horseshoe(map, visited, dx, dy, n, len, 1, 0, 0)){
			ans = 2 * len;
		}
	}
	printf("%d", ans);
	return 0;
}
