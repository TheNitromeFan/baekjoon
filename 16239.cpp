#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int sum = 0;
	for(int i = 1; i < k; ++i){
		printf("%d\n", i);
		sum += i;
	}
	printf("%d", n - sum);
	return 0;
}
