#include <cstdio>
#include <cstdlib>
#define MAX 10

bool touch(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2) <= 2;
}

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};

int main(){
	int n;
	scanf("%d", &n);
	int g[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d", &g[i][j]);
		}
	}
	int ans = 1000000;
	for(int c1 = 0; c1 < n * n; ++c1){
		int x1 = c1 / n, y1 = c1 % n;
		if(x1 == 0 || x1 == n - 1 || y1 == 0 || y1 == n - 1){
			continue;
		}
		for(int c2 = 0; c2 < c1; ++c2){
			int x2 = c2 / n, y2 = c2 % n;
			if(x2 == 0 || x2 == n - 1 || y2 == 0 || y2 == n - 1 || touch(x1, y1, x2, y2)){
				continue;
			}
			for(int c3 = 0; c3 < c2; ++c3){
				int x3 = c3 / n, y3 = c3 % n;
				if(x3 == 0 || x3 == n - 1 || y3 == 0 || y3 == n - 1 || touch(x1, y1, x3, y3) || touch(x2, y2, x3, y3)){
					continue;
				}
				// printf("%d %d %d %d", x1, y1, x3, y3);
				int cmp = 0;
				for(int i = 0; i < 5; ++i){
					cmp += g[x1 + dx[i]][y1 + dy[i]] + g[x2 + dx[i]][y2 + dy[i]] + g[x3 + dx[i]][y3 + dy[i]];
				}
				if(cmp < ans){
					ans = cmp;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
