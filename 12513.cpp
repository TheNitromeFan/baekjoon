#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		int sum = 0, min = 200000000, xsum = 0;
		for(int i = 0; i < n; ++i){
			int ci;
			scanf("%d", &ci);
			sum += ci;
			xsum ^= ci;
			if(ci < min){
				min = ci;
			}
		}
		printf("Case #%d: ", a0);
		if(xsum == 0){
			printf("%d", sum - min);
		}else{
			printf("NO");
		}
		printf("\n");
	}
	return 0;
}
