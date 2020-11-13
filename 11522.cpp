#include <cstdio>

int main(){
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; ++i){
		int k, n;
		scanf("%d %d", &k, &n);
		printf("%d %d %d %d\n", k, (n * n + n) / 2, n * n, n * n + n);
	}
	return 0;
}
