#include <cstdio>

long divisions(int coins[20], int n, int target){
	
	long ways[10001] = {1};
	for(int i = 0; i < n; i++)
		for(int j = coins[i]; j <= target; j++)
			ways[j] += ways[j - coins[i]];
	return ways[target];
}

int main(void){
	
	int t;
	scanf("%d", &t);
	int n, m;
	int coins[20];
	for(int i = 0; i < t; i++){
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
			scanf("%d", &coins[j]);
		scanf("%d", &m);
		printf("%ld\n", divisions(coins, n, m));
	}
	return 0;
}
