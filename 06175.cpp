#include <cstdio>
#define MAXN 101
#define MAXT 16

int main(){
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);
	char map[MAXN][MAXN];
	for(int i = 0; i < n; ++i){
		scanf("%s", map[i]);
	}
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	--r1;
	--c1;
	--r2;
	--c2;
	long long dp[MAXN][MAXN][MAXT] = {};
	dp[r1][c1][0] = 1;
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	for(int time = 1; time <= t; ++time){
		for(int x = 0; x < n; ++x){
			for(int y = 0; y < m; ++y){
				if(map[x][y] == '*'){
					continue;
				}
				for(int i = 0; i < 4; ++i){
					int px = x + dx[i];
					int py = y + dy[i];
					if(px >= 0 && px < n && py >= 0 && py < m){
						dp[x][y][time] += dp[px][py][time - 1];
					}
				}
			}
		}
	}
	printf("%lld\n", dp[r2][c2][t]);
	return 0;
}
