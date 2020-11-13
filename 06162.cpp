#include <cstdio>

int main(){
	int k;
	scanf("%d", &k);
	for(int a0 = 1; a0 <= k; ++a0){
		long long e, a;
		scanf("%lld %lld", &e, &a);
		printf("Data Set %d:\n", a0);
		if(e <= a){
			printf("no drought\n\n");
			continue;
		}
		while(e > 5 * a){
			printf("mega ");
			a *= 5;
		}
		printf("drought\n\n");
	}
	return 0;
}
