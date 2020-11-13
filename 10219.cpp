#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		char grill[12][12];
		int h, w;
		scanf("%d %d", &h, &w);
		for(int i = 0; i < h; ++i){
			scanf("%s", grill[i]);
			for(int j = w - 1; j >= 0; --j){
				printf("%c", grill[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
