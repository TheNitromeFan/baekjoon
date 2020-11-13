#include <cstdio>

int coins[10];

int number(int value, int n){
	int count = 0;
	int i = n-1;
	while(value > 0){
		if(coins[i] <= value){
			value -= coins[i];
			++count;
		}else{
			--i;
		}
	}
	return count;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%d", &coins[i]);
	}
	printf("%d", number(k, n));
	return 0;
}
