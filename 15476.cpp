#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::min;

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	int a[25][25];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	int minSum = 1000000000;
	for(int x = 0; x < h; ++x){
		for(int y = 0; y < w; ++y){
			int sum = 0;
			for(int i = 0; i < h; ++i){
				for(int j = 0; j < w; ++j){
					sum += a[i][j] * min(abs(i - x), abs(j - y));
				}
			}
			if(sum < minSum){
				minSum = sum;
			}
		}
	}
	printf("%d", minSum);
	return 0;
}
