#include <cstdio>

int main(){
	int coins[100] = {};
	for(int i = 1; i < 100; ++i){
		coins[i] = coins[i - 1] + 1;
		if(i >= 10 && coins[i] > coins[i - 10] + 1){
			coins[i] = coins[i - 10] + 1;
		}
		if(i >= 25 && coins[i] > coins[i - 25] + 1){
			coins[i] = coins[i - 25] + 1;
		}
	}
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		long long price;
		scanf("%lld", &price);
		int ans = 0;
		while(price){
			ans += coins[price % 100];
			price /= 100;
		}
		printf("%d\n", ans);
	}
	return 0;
}
