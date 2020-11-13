#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	static int w[3000000];
	int maxLoss = 0, maxWeight = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &w[i]);
		if(maxWeight < w[i]){
			maxWeight = w[i];
		}else if(maxWeight - w[i] > maxLoss){
			maxLoss = maxWeight - w[i];
		}
	}
	printf("%d", maxLoss);
	return 0;
}
