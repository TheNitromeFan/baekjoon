#include <cstdio>
#define MAX (100000 + 1)

int main(){
	long long psum[MAX] = {};
	int a[MAX];
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		psum[i] = psum[i - 1] + a[i];
	}
	int m;
	scanf("%d", &m);
	for(int q = 0; q < m; ++q){
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%lld\n", psum[j] - psum[i - 1]);
	}
	return 0;
}
