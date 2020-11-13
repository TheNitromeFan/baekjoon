#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::sort;

int main(){
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	for(int i = 0; i < n; ++i){
		printf("%d\n", a[i]);
	}
	free(a);
	return 0;
}
