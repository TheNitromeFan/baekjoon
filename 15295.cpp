#include <cstdio>

int main(){
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; ++i){
		int k, n;
		scanf("%d %d", &k, &n);
		printf("%d %d\n", k, n * (n + 3) / 2);
	}
	return 0;
}
