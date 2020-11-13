#include <cstdio>
#define MAX (100 + 1)

int main(){
	while(true){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == 0 && y == 0){
			break;
		}
		int cells[MAX][MAX] = {};
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			int xc, yc;
			scanf("%d %d", &xc, &yc);
			++cells[xc][yc];
		}
		int n;
		scanf("%d", &n);
		int ans = 0;
		for(int j = 0; j < n; ++j){
			int xc, yc;
			scanf("%d %d", &xc, &yc);
			ans += cells[xc][yc];
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
