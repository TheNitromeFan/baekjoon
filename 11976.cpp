#include <cstdio>

int main(){
	int before[4], after[4];
	for(int i = 0; i < 4; ++i){
		scanf("%d %d", &before[i], &after[i]);
	}
	int ans[4] = {};
	for(int i = 3; i >= 1; --i){
		if(before[i] < after[i]){
			ans[i] = after[i] - before[i];
			before[i - 1] -= after[i] - before[i];
			before[i] = after[i];
		}
	}
	for(int i = 1; i <= 3; ++i){
		printf("%d\n", ans[i]);
	}
	return 0;
}
