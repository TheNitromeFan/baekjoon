#include <cstdio>

int main(){
	int c, n;
	scanf("%d %d", &c, &n);
	int coins[10];
	for(int i = 0; i < n; ++i){
		scanf("%d", &coins[i]);
	}
	int change[1001] = {};
	for(int j = 1; j <= c; ++j){
		change[j] = 2000;
		for(int i = 0; i < n; ++i){
			if(coins[i] > j){
				continue;
			}
			if(change[j] > change[j - coins[i]] + 1){
				change[j] = change[j - coins[i]] + 1;
			}
		}
	}
	printf("%d", change[c]);
	return 0;
}
