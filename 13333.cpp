#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int a[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int k = 0;
	for(; k <= n && k <= 10000; ++k){
		if(a[n - k] >= k && ((k == n && k <= a[0]) || ((k < n) && a[n - k - 1] <= k))){
			printf("%d", k);
			break;
		}
	}
	return 0;
}

