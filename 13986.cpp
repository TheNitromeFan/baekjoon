#include <cstdio>
#include <algorithm>

using std::swap;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char grid[50][51];
	for(int i = 0; i < n; ++i){
		scanf("%s", grid[i]);
	}
	for(int i = n - 1; i >= 0; --i){
		for(int j = 0; j < m; ++j){
			if(grid[i][j] == 'o'){
				int y = i;
				while(y + 1 < n && grid[y + 1][j] != '#'){
					swap(grid[y][j], grid[y + 1][j]);
					++y;
				}
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}
