#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int min[10001];
	int coins[100];
	for(int i = 1; i <= k; ++i){
		min[i] = -1;
	}
	for(int i = 0; i < n; ++i){
		int coin;
		scanf("%d", &coin);
		coins[i] = coin;
		if(coin <= k){
			min[coin] = 1;
		}
	}
	for(int j = 1; j <= k; ++j){
		for(int i = 0; i < n; ++i){
			if(j - coins[i] >= 1 && min[j - coins[i]] != -1 && (min[j] == -1 || min[j] > min[j - coins[i]] + 1)){
				min[j] = min[j - coins[i]] + 1;
			}
		}
	}
	printf("%d", min[k]);
	return 0;
}
