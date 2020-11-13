#include <cstdio>

int main(){
	int tc;
	scanf("%d", &tc);
	for(int a0 = 0; a0 < tc; ++a0){
		int price;
		scanf("%d", &price);
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			int q, p;
			scanf("%d %d", &q, &p);
			price += q * p;
		}
		printf("%d\n", price);
	}
	return 0;
}
