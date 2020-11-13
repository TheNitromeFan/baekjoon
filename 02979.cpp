#include <cstdio>
#define MAX 100

int main(){
	int prices[4] = {};
	scanf("%d %d %d", &prices[1], &prices[2], &prices[3]);
	int trucks[MAX + 1] = {};
	for(int i = 0; i < 3; ++i){
		int a, d;
		scanf("%d %d", &a, &d);
		for(int j = a; j < d; ++j){
			++trucks[j];
		}
	}
	int ans = 0;
	for(int j = 0; j <= MAX; ++j){
		ans += prices[trucks[j]] * trucks[j];
	}
	printf("%d", ans);
	return 0;
}
