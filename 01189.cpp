#include <cstdio>

long long ways(char map[][6], bool visited[][5], int dx[4], int dy[4], int r, int c, int k, int x, int y){
	--k;
	if(k == 0){
		return (x == 0 && y == c - 1);
	}
	long long ret = 0;
	for(int i = 0; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] == '.' && !visited[nx][ny]){
			visited[nx][ny] = true;
			ret += ways(map, visited, dx, dy, r, c, k, nx, ny);
			visited[nx][ny] = false;
		}
	}
	return ret;
}

int main(){
	int r, c, k;
	scanf("%d %d %d", &r, &c, &k);
	char map[5][6];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	bool visited[5][5] = {};
	visited[r - 1][0] = true;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	printf("%lld\n", ways(map, visited, dx, dy, r, c, k, r - 1, 0));
	return 0;
}
