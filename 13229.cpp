#include <cstdio>
#define MAX (100000 + 1)

int main(){
	int n;
	scanf("%d", &n);
	int a[MAX], psum[MAX] = {};
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		psum[i] = psum[i - 1] + a[i];
	}
	int m;
	scanf("%d", &m);
	for(int j = 0; j < m; ++j){
		int start, end;
		scanf("%d %d", &start, &end);
		printf("%d\n", psum[end + 1] - psum[start]);
	}
	return 0;
}
