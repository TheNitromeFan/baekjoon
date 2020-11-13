#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans[5] = {};
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == 0 || y == 0){
			++ans[0];
		}else if(x > 0 && y > 0){
			++ans[1];
		}else if(y > 0){
			++ans[2];
		}else if(x < 0){
			++ans[3];
		}else{
			++ans[4];
		}
	}
	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d", ans[1], ans[2], ans[3], ans[4], ans[0]);
	return 0;
}
