#include <cstdio>


int kth_factor(int n, int k){
	
	int count = 0;
	for(int i = 1; i <= n; i++)
		if(n % i == 0){
			count++;
			if(count == k) return i;
		}
	return 0;
}

int main(void){
	
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", kth_factor(n, k));
	return 0;
}
