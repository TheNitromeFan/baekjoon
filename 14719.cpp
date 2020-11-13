#include <cstdio>
#include <algorithm>

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	int heights[501];
	for(int i = 1; i <= w; ++i){
		scanf("%d", &heights[i]);
	}
	int maxleft[501], maxright[501];
	int cur;
	cur = 0;
	for(int i = 1; i < w; ++i){
		if(heights[i] > cur){
			cur = heights[i];
		}
		maxleft[i] = cur;
	}
	cur = 0;
	for(int i = w; i > 1; --i){
		if(heights[i] > cur){
			cur = heights[i];
		}
		maxright[i] = cur;
	}
	int cnt = 0;
	for(int i = 2; i < w; ++i){
		int cmp = std::min(maxleft[i-1], maxright[i+1]);
		if(cmp > heights[i]){
			cnt += cmp - heights[i];
		}
	}
	printf("%d", cnt);
	return 0;
}
