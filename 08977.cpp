#include <cstdio>
#define MAX (100 + 1)

int main(){
	int n, k, b;
	scanf("%d %d %d", &n, &k, &b);
	int x[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x[i]);
	}
	int idx = (b - 1) % n + 1;
	int ans = 0;
	for(int j = 0; j < k; ++j){
		ans += x[idx];
		++idx;
		if(idx > n){
			idx = 1;
		}
	}
	printf("%d", ans);
	return 0;
}
