#include <cstdio>
#define MAXM (50 + 1)
#define MAXN (1000 + 1)

int main(){
	while(true){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0){
			break;
		}
		int p[MAXM][MAXN];
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= n; ++j){
				scanf("%d", &p[i][j]);
			}
		}
		int max = 0;
		for(int j = 1; j <= n; ++j){
			int score = 0;
			for(int i = 1; i <= m; ++i){
				score += p[i][j];
			}
			if(max < score){
				max = score;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
