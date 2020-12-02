#include <cstdio>

bool can_place_row(char map[][101], int n, int m, int d, int x, int y){
	for(int j = y; j < y + d; ++j){
		if(map[x][j] == '#'){
			return false;
		}
	}
	return true;
}

bool can_place_col(char map[][101], int n, int m, int d, int x, int y){
	for(int i = x; i < x + d; ++i){
		if(map[i][y] == '#'){
			return false;
		}
	}
	return true;
}

int main(){
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	char map[101][101];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j + d <= m; ++j){
			ans += can_place_row(map, n, m, d, i, j);
		}
	}
	for(int i = 0; i + d <= n; ++i){
		for(int j = 0; j < m; ++j){
			ans += can_place_col(map, n, m, d, i, j);
		}
	}
	printf("%d", ans);
	return 0;
}
