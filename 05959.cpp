#include <cstdio>
#include <cmath>

struct circle{
	int x;
	int y;
	int r;
} circles[401];

bool overlap(int i, int j){
	double d = sqrt((circles[i].x - circles[j].x) * (circles[i].x - circles[j].x)
					+ (circles[i].y - circles[j].y) * (circles[i].y - circles[j].y));
	return d < circles[i].r + circles[j].r;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d %d %d", &circles[i].x, &circles[i].y, &circles[i].r);
	}
	for(int i = 1; i <= n; ++i){
		int cnt = 0;
		for(int j = 1; j <= n; ++j){
			if(overlap(i, j)){
				++cnt;
			}
		}
		--cnt;
		printf("%d\n", cnt);
	}
	return 0;
}
