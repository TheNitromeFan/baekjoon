#include <cstdio>
#include <cstdlib>

struct pos{
	int x;
	int y;
	bool swatted;
} bug[100];

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &bug[i].x, &bug[i].y);
			bug[i].swatted = false;
		}
		int m;
		scanf("%d", &m);
		for(int j = 0; j < m; ++j){
			int xj, yj;
			scanf("%d %d", &xj, &yj);
			for(int i = 0; i < n; ++i){
				if(abs(xj - bug[i].x) <= 50 && abs(yj - bug[i].y) <= 50){
					bug[i].swatted = true;
				}
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			if(bug[i].swatted){
				++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
