#include <cstdio>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);
	static long long a[500000];
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	std::sort(a, a + n);
	long long ans = 0;
	for(int i = 0; i < n-1; ++i){
		ans += a[i] * (sum - a[i]);
		sum -= a[i];
	}
	printf("%lld", ans);
	return 0;
}
