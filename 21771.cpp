#include <cstdio>
#define MAX 101

int main(){
	int r, c, rg, cg, rp, cp;
	scanf("%d %d %d %d %d %d", &r, &c, &rg, &cg, &rp, &cp);
	char map[MAX][MAX];
	int cnt = 0;
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < c; ++j){
			if(map[i][j] == 'P'){
				++cnt;
			}
		}
	}
	printf("%d", cnt < rp * cp);
	return 0;
}
