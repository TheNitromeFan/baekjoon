#include <cstdio>

int main(){
	int n, k;
	while(scanf("%d %d", &n, &k) == 2){
		int ans = n;
		while(n >= k){
			++ans;
			n -= k;
			++n;
		}
		printf("%d\n", ans);
	}
	return 0;
}
