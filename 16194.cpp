#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int p[1001] = {};
	for(int i = 1; i <= n; ++i){
		scanf("%d", &p[i]);
	}
	int minPrice[1001] = {};
	for(int i = 1; i <= n; ++i){
		minPrice[i] = p[i];
		for(int j = 1; j < i; ++j){
			if(minPrice[i] > p[j] + minPrice[i - j]){
				minPrice[i] = p[j] + minPrice[i - j];
			}
		}
	}
	printf("%d", minPrice[n]);
	return 0;
}
