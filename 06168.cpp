#include <cstdio>
#include <algorithm>

int main(){
	int cows[30001] = {};
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &cows[i]);
	}
	int twosSum[30002] = {}, onesSum[30002] = {};
	for(int i = 1; i <= n; ++i){
		twosSum[i] = twosSum[i - 1] + (cows[i] == 2);
	}
	for(int i = n; i >= 1; --i){
		onesSum[i] = onesSum[i + 1] + (cows[i] == 1);
	}
	/*
	for(int i = 1; i <= n; ++i){
		printf("%d ", onesSum[i]);
	}
	printf("\n");
	for(int i = 1; i <= n; ++i){
		printf("%d ", twosSum[i]);
	}
	printf("\n");
	*/
	int ans = n;
	for(int i = 0; i <= n; ++i){
		ans = std::min(ans, twosSum[i] + onesSum[i + 1]);
	}
	printf("%d", ans);
	return 0;
}
