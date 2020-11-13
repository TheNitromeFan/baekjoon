#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>

using std::sort;
using std::greater;

int main(){
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a+n, greater<int>());
	for(int i = 0; i < n; ++i){
		printf("%d\n", a[i]);
	}
	free(a);
	return 0;
}
