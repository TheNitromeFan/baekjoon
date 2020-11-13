#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX (500000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	std::sort(a + 1, a + n + 1);
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
		ans += abs(a[i] - i);
	}
	printf("%lld", ans);
	return 0;
}
