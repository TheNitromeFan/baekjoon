#include <cstdio>

int main(){
	int x, y, l;
	scanf("%d %d %d", &x, &y, &l);
	bool mowed[241][241] = {};
	for(int a0 = 0; a0 < l; ++a0){
		int xll, yll, xur, yur;
		scanf("%d %d %d %d", &xll, &yll, &xur, &yur);
		for(int x1 = xll; x1 <= xur; ++x1){
			for(int y1 = yll; y1 <= yur; ++y1){
				mowed[x1][y1] = true;
			}
		}
	}
	int ans = 0;
	for(int x1 = 1; x1 <= x; ++x1){
		for(int y1 = 1; y1 <= y; ++y1){
			if(mowed[x1][y1]){
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
