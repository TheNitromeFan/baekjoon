#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		char draw[101][101];
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				draw[i][j] = '.';
			}
		}
		int req;
		scanf("%d", &req);
		for(int r = 0; r < req; ++r){
			char type[10];
			int startx, starty, w, h;
			char c;
			scanf("%s %d %d %d %d %c", type, &startx, &starty, &w, &h, &c);
			if(type[0] == 'F'){
				for(int i = startx; i < startx + w; ++i){
					for(int j = starty; j < starty + h; ++j){
						draw[i][j] = c;
					}
				}
			}else if(type[0] == 'E'){
				for(int i = startx; i < startx + w; ++i){
					for(int j = starty; j < starty + h; ++j){
						if(i == startx || i == startx + w - 1 || j == starty || j == starty + h - 1){
							draw[i][j] = c;
						}
					}
				}
			}
		}
		printf("Case %d:\n", a0);
		for(int j = n; j > 0; --j){
			for(int i = 1; i <= n; ++i){
				printf("%c", draw[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
