#include <cstdio>
#include <algorithm>

using std::sort;

int main(){
	int n;
	scanf("%d", &n);
	int a[500000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for(int k = 0; k <= n; ++k){
		if(a[n - k] >= k && ((k == n && k <= a[0]) || ((k < n) && a[n - k - 1] <= k))){
			printf("%d", k);
			break;
		}
	}
	return 0;
}
