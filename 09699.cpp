#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int ans = 0;
		for(int j = 0; j < 5; ++j){
			int x;
			scanf("%d", &x);
			if(ans < x){
				ans = x;
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
