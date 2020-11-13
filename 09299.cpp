#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		printf("Case %d: %d", a0, n-1);
		for(int i = n; i > 0; --i){
			int a;
			scanf("%d", &a);
			printf(" %d", i * a);
		}
		scanf("%d", &n);
		printf("\n");
	}
	return 0;
}
