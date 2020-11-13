#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", (n - k) / (k - 1));
	}
	return 0;
}
