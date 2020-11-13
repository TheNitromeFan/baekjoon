#include <cstdio>

struct biomes{
	int jungle;
	int ocean;
	int ice;
};

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	int k;
	scanf("%d", &k);
	static struct biomes b[1001][1001];
	for(int j = 0; j <= n; ++j){
		b[0][j].jungle = 0;
		b[0][j].ocean = 0;
		b[0][j].ice = 0;
	}
	for(int i = 0; i <= m; ++i){
		b[i][0].jungle = 0;
		b[i][0].ocean = 0;
		b[i][0].ice = 0;
	}
	char s[1002];
	for(int i = 1; i <= m; ++i){
		scanf("%s", s);
		int running_jungle = 0, running_ocean = 0, running_ice = 0;
		for(int j = 1; j <= n; ++j){
			if(s[j-1] == 'J'){
				++running_jungle;
			}else if(s[j-1] == 'O'){
				++running_ocean;
			}else{
				++running_ice;
			}
			b[i][j].jungle = b[i-1][j].jungle + running_jungle;
			b[i][j].ocean = b[i-1][j].ocean + running_ocean;
			b[i][j].ice = b[i-1][j].ice + running_ice;
		}
	}
	for(int q = 0; q < k; ++q){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d %d %d\n", 
				b[x2][y2].jungle - b[x2][y1-1].jungle - b[x1-1][y2].jungle + b[x1-1][y1-1].jungle,
				b[x2][y2].ocean - b[x2][y1-1].ocean - b[x1-1][y2].ocean + b[x1-1][y1-1].ocean,
				b[x2][y2].ice - b[x2][y1-1].ice - b[x1-1][y2].ice + b[x1-1][y1-1].ice);
	}
	/*
	for(int i = 0; i <= m; ++i){
		for(int j = 0; j <= n; ++j){
			printf("(%d, %d, %d) ", b[i][j].jungle, b[i][j].ocean, b[i][j].ice);
		}
		printf("\n");
	}
	*/
	return 0;
}
