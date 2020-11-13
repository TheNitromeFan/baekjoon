#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int h[20], j[20];
	for(int i = 0; i < n; ++i){
		scanf("%d", &h[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d", &j[i]);
	}
	int ans = 0;
	int hsum, jsum;
	for(int x = 1; x <= (1 << n); ++x){
		hsum = 0;
		jsum = 0;
		int y = x;
		for(int i = 0; i < n; ++i){
			if(y % 2){
				hsum += h[i];
				jsum += j[i];
			}
			y /= 2;
		}
		if(hsum < 100 && jsum > ans){
			ans = jsum;
		}
	}
	printf("%d", ans);
	return 0;
}
