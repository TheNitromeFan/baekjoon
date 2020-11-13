#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		printf("%d %d %d\n", (n * n + n) / 2, n * n, n * n + n);
	}
	return 0;
}
