#include <cstdio>

struct meeting{
	int t;
	int p;
} days[1500002];

int main(){
	int n;
	scanf("%d", &n);
	int profit[1500002] = {};
	int maxProfit = -1;
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &days[i].t, &days[i].p);
		if(profit[i + 1] < profit[i]){
			profit[i + 1] = profit[i];
		}
		if(i + days[i].t <= n + 1 && profit[i + days[i].t] < profit[i] + days[i].p){
			profit[i + days[i].t] = profit[i] + days[i].p;
		}
		if(maxProfit < profit[i]){
			maxProfit = profit[i];
		}
	}
	if(maxProfit < profit[n + 1]){
		maxProfit = profit[n + 1];
	}
	/*
	for(int i = 1; i <= n + 1; ++i){
		printf("%d ", profit[i]);
	}
	*/
	printf("%d", maxProfit);
	return 0;
}
