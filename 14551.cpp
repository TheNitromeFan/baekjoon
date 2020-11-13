#include <cstdio>


int main(void){
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int a[101];
	int product = 1 % m;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		if(a[i] == 0)
			a[i] = 1;
		product = product * a[i] % m;
	}
	printf("%d", product);
	return 0;
}
