#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int h, y;
	scanf("%d %d", &h, &y);
	int max_h[11];
	max_h[0] = h;
	for(int i = 1; i <= y; ++i){
		max_h[i] = (int)(max_h[i - 1] * 1.05);
		if(i >= 3){
			max_h[i] = max(max_h[i], (int)(max_h[i - 3] * 1.2));
		}
		if(i >= 5){
			max_h[i] = max(max_h[i], (int)(max_h[i - 5] * 1.35));
		}
	}
	printf("%d", max_h[y]);
	return 0;
}
