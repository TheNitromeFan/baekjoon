#include <cstdio>

int main(){
	int cows[101][101];
	int nr, nc;
	scanf("%d %d", &nr, &nc);
	for(int i = 1; i <= nr; ++i){
		for(int j = 1; j <= nc; ++j){
			scanf("%d", &cows[i][j]);
		}
	}
	int ans = 0, ansr = 0, ansc = 0;
	for(int i = 1; i <= nr - 2; ++i){
		for(int j = 1; j <= nc - 2; ++j){
			int sum = 0;
			for(int x = i; x <= i + 2; ++x){
				for(int y = j; y <= j + 2; ++y){
					sum += cows[x][y];
				}
			}
			if(sum > ans){
				ans = sum;
				ansr = i;
				ansc = j;
			}
		}
	}
	printf("%d\n%d %d", ans, ansr, ansc);
	return 0;
}
