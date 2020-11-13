#include <cstdio>
#include <cmath>

int main(){
	while(true){
		double prices[101];
		scanf("%lf", &prices[1]);
		if(prices[1] == -1){
			break;
		}
		int n;
		scanf("%lf %lf %d", &prices[2], &prices[3], &n);
		for(int i = 4; i <= n; ++i){
			prices[i] = floor(prices[i-3] * prices[i-2] / prices[i-1] * 100 + 0.5) / 100;
		}
		printf("Month %d cost: $%.2f\n", n, prices[n]);
	}
	return 0;
}
