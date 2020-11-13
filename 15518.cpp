#include <cstdio>

int main(){
	int n, h, w;
	scanf("%d %d %d", &n, &h, &w);
	int window[10000] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < w; ++j){
			window[w * (i - 1) + j] = 1;
		}
	}
	for(int i = 1; i <= n; ++i){
		int wi;
		scanf("%d", &wi);
		if(i % 2 == 1){
			for(int j = 0, x = w * (i - 1); j < wi; ++j, ++x){
				--window[x];
				++window[x + w];
			}
		}else{
			for(int j = 0, x = w * i - 1; j < wi; ++j, --x){
				--window[x];
				++window[x - w];
			}
		}
	}
	int area = 0;
	for(int x = 0; x < w * n; ++x){
		if(window[x] == 0){
			area += h;
		}
	}
	printf("%d", area);
	return 0;
}
