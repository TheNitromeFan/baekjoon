#include <cstdio>
#include <cstring>
#define MAX 501

int cache[MAX][MAX];
bool visited[MAX][MAX];

int dp(char map[][MAX], int n, int m, int x, int y){
	if(cache[x][y] != -1){
		return cache[x][y];
	}
	if(visited[x][y]){
		cache[x][y] = 0;
		return 0;
	}
	visited[x][y] = true;
	int nx = x, ny = y;
	if(map[x][y] == 'D'){
		++nx;
	}else if(map[x][y] == 'U'){
		--nx;
	}else if(map[x][y] == 'R'){
		++ny;
	}else{
		--ny;
	}
	if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)){
		cache[x][y] = 1;
		return 1;
	}
	cache[x][y] = dp(map, n, m, nx, ny);
	return cache[x][y];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char map[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	memset(cache, -1, sizeof(cache));
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			ans += dp(map, n, m, i, j);
		}
	}
	printf("%d\n", ans);
	return 0;
}
