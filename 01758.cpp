#include <cstdio>
#include <algorithm>
#include <functional>
#define MAX 100000

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + n, greater<int>());
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += max(a[i] - i, 0);
	}
	printf("%lld", ans);
	return 0;
}
