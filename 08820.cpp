#include <cstdio>

int main(){
	int z;
	scanf("%d", &z);
	for(int a0 = 0; a0 < z; ++a0){
		int n, k;
		scanf("%d %d", &n, &k);
		int a[100001];
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		long long cust = 0;
		long long maxProfit = 0;
		for(int i = n; i >= k; --i){
			cust += a[i];
			long long profit = cust * (i - k);
			if(maxProfit < profit){
				maxProfit = profit;
			}
		}
		printf("%lld\n", maxProfit);
	}
	return 0;
}
