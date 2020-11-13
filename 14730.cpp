#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int c, k;
		scanf("%d %d", &c, &k);
		ans += c * k;
	}
	printf("%d", ans);
	return 0;
}
