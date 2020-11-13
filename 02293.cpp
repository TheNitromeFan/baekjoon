#include <cstdio>
#include <cstdlib>


int divisions(int k, int *coins, int n){
	
	int *ways = (int *)malloc((k+1) * sizeof(int));
	for(int i = 1; i <= k; i++) *(ways+i) = 0;
	*ways = 1;
	for(int i = 0; i < n; i++)
		for(int j = *(coins+i); j <= k; j++)
			*(ways+j) += *(ways+j-*(coins+i));
	int answer = *(ways+k);
	free(ways);
	return answer;
}

int main(void){
	
	int n, k;
	scanf("%d %d", &n, &k);
	int *coins = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) scanf("%d", coins+i);
	printf("%d", divisions(k, coins, n));
	free(coins);
	return 0;
}
