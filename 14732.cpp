#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	bool covered[501][501] = {};
	for(int i = 0; i < n; ++i){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int i = x1; i < x2; ++i){
			for(int j = y1; j < y2; ++j){
				covered[i][j] = true;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= 500; ++i){
		for(int j = 0; j <= 500; ++j){
			if(covered[i][j]){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
