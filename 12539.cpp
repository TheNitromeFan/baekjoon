#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int m;
		scanf("%d", &m);
		int p[13];
		for(int j = 1; j <= 12; ++j){
			scanf("%d", &p[j]);
		}
		int maxProfit = 0;
		int bestBuy = 0, bestSell = 0;
		for(int j = 1; j <= 12; ++j){
			for(int k = 1; k < j; ++k){
				int profit = m / p[k] * (p[j] - p[k]);
				if(maxProfit < profit || (maxProfit == profit && p[bestBuy] > p[k])){
					maxProfit = profit;
					bestBuy = k;
					bestSell = j;
				}
			}
		}
		printf("Case #%d: ", i);
		if(maxProfit != 0){
			printf("%d %d %d\n", bestBuy, bestSell, maxProfit);
		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
