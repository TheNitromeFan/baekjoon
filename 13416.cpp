#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		int ans = 0, cmp;
		for(int j = 0; j < n; ++j){
			cmp = 0;
			for(int k = 0; k < 3; ++k){
				int stock;
				scanf("%d", &stock);
				if(cmp < stock){
					cmp = stock;
				}
			}
			ans += cmp;
		}
		printf("%d\n", ans);
	}
	return 0;
}
