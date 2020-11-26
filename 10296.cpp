#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int g, k;
		scanf("%d %d", &g, &k);
		if(g <= 100){
			printf("0\n");
			continue;
		}
		printf("%d\n", (g - 100 - 1) / (100 * k - 90) + 1);
	}
	return 0;
}
