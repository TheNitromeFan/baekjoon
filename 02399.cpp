#include <cstdio>
#include <cstdlib>

int main(){
	int n;
	scanf("%d", &n);
	int a[10000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			ans += 2 * abs(a[i] - a[j]);
		}
	}
	printf("%lld", ans);
	return 0;
}
