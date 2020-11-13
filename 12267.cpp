#include <cstdio>
#include <cstring>
#define MAX (6 * 6 + 1)

bool valid(int grid[][MAX], int n){
	int cnt[MAX];
	for(int i = 1; i <= n * n; ++i){
		memset(cnt, 0, sizeof(cnt));
		for(int j = 1; j <= n * n; ++j){
			if(grid[i][j] > n * n){
				return false;
			}
			++cnt[grid[i][j]];
			if(cnt[grid[i][j]] > 1){
				return false;
			}
		}
	}
	for(int j = 1; j <= n * n; ++j){
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n * n; ++i){
			if(grid[i][j] > n * n){
				return false;
			}
			++cnt[grid[i][j]];
			if(cnt[grid[i][j]] > 1){
				return false;
			}
		}
	}
	for(int box = 0; box < n * n; ++box){
		memset(cnt, 0, sizeof(cnt));
		for(int i = (box / n) * n + 1; i <= (box / n) * n + n; ++i){
			for(int j = (box % n) * n + 1; j <= (box % n) * n + n; ++j){
				if(grid[i][j] > n * n){
					return false;
				}
				++cnt[grid[i][j]];
				if(cnt[grid[i][j]] > 1){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int n;
		scanf("%d", &n);
		int grid[MAX][MAX];
		for(int j = 1; j <= n * n; ++j){
			for(int k = 1; k <= n * n; ++k){
				scanf("%d", &grid[j][k]);
			}
		}
		printf("Case #%d: %s\n", i, valid(grid, n) ? "Yes" : "No");
	}
	return 0;
}
