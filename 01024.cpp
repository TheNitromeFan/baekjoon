#include <cstdio>

int main(){
	int n, l;
	scanf("%d %d", &n, &l);
	for(int k = l; k * (k-1) <= 2 * n && k <= 100; ++k){
		if((2 * n) % k == 0 && ((2 * n) / k - k + 1) % 2 == 0){
			int a = ((2 * n) / k - k + 1) / 2;
			for(int i = a; i < a+k; ++i){
				printf("%d ", i);
			}
			return 0;
		}
	}
	printf("-1");
	return 0;
}
