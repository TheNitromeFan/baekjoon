#include <cstdio>
#include <algorithm>

int main(){
	int n;
	scanf("%d", &n);
	static int a[500000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	for(int i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	return 0;
}
