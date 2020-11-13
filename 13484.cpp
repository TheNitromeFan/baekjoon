#include <cstdio>

int main(){
	int x, n;
	scanf("%d %d", &x, &n);
	int ans = x * (n + 1);
	for(int i = 0; i < n; ++i){
		int p;
		scanf("%d", &p);
		ans -= p;
	}
	printf("%d", ans);
	return 0;
}
