#include <cstdio>

int main(){
	long long prices[5] = {35034, 23090, 19055, 12530, 18090};
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		long long parts[5];
		long long cost = 0;
		for(int i = 0; i < 5; ++i){
			scanf("%lld", &parts[i]);
			cost += parts[i] * prices[i];
		}
		printf("$%lld.", cost / 100);
		if(cost % 100 < 10){
			printf("0");
		}
		printf("%lld\n", cost % 100);
	}
	return 0;
}
