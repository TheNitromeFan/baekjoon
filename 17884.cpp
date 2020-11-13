#include <cstdio>

int main(){
	int order[101];
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		int x;
		scanf("%d", &x);
		order[x] = i;
	}
	printf("1");
	for(int x = 0; x < n - 1; ++x){
		printf(" %d", order[x]);
	}
	return 0;
}
