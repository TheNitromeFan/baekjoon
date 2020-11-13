#include <cstdio>
#define MAX 100000

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[MAX+1], sum[MAX+1] = {};
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for(int j = 0; j < m; ++j){
		int low, high;
		scanf("%d %d", &low, &high);
		printf("%d\n", sum[high] - sum[low - 1]);
	}
	return 0;
}
