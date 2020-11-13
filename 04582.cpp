#include <cstdio>
#define MAX (30000 + 1)

using namespace std;

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		int g;
		scanf("%d", &g);
		int tallies[4][2 * MAX + 1] = {};
		for(int a0 = 0; a0 < g; ++a0){
			int k, x, y, s, t;
			scanf("%d %d %d %d %d", &k, &x, &y, &s, &t);
			for(int i = 0; i < k; ++i){
				++tallies[0][x];
				++tallies[1][y];
				++tallies[2][x + y];
				++tallies[3][n + 1 + x - y];
				x += s;
				y += t;
			}
		}
		int ans = 0;
		for(int i = 0; i < 4; ++i){
			for(int j = 0; j <= 2 * MAX; ++j){
				if(tallies[i][j] > 0){
					ans += tallies[i][j] - 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
