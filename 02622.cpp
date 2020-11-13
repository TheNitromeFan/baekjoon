#include <cstdio>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int a = 1; 3 * a <= n; ++a){
		ans += (n - a) / 2 - std::max(a - 1, n / 2 - a);
	}
	printf("%d", ans);
	return 0;
}
