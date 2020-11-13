#include <cstdio>
#define SONG 100
#define MAX 1000

int main(){
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);
	int songs[SONG + 1];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &songs[i]);
	}
	bool dp[SONG + 1][MAX + 1] = {};
	dp[0][s] = true;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			if(!dp[i - 1][j]){
				continue;
			}
			if(j - songs[i] >= 0){
				dp[i][j - songs[i]] = true;
			}
			if(j + songs[i] <= m){
				dp[i][j + songs[i]] = true;
			}
		}
	}
	for(int j = m; j >= 0; --j){
		if(dp[n][j]){
			printf("%d", j);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
